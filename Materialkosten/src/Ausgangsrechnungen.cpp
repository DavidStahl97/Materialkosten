#include "Ausgangsrechnungen.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include "CsvDatei.h"
#include "Common.h"

/// <summary>
/// 
/// </summary>
void Ausgangsrechnungen::AlleMaterialienFinden(const std::string& ordner)
{
	for (auto& p : std::experimental::filesystem::directory_iterator(ordner))
	{
		std::string datei(p.path().string());
		LOG(datei);
		
		MaterialFinden(datei);
	}
}

void Ausgangsrechnungen::MaterialFinden(const std::string& datei)
{
	IfCsvDatei quelle(datei);
	if (!quelle.Good())
	{
		std::cout << "quelle nicht gefunden" << std::endl;
		return;
	}
	else
	{
		while (quelle.Good())
		{
			std::vector<std::string> zeile;
			quelle.GetZeile(zeile);

			try
			{
				if (zeile.size() < 5)
				{
					continue;
				}

				std::stod(zeile[1]);
				std::stod(zeile[4]);

				std::string& stringPreis = zeile[3];
				size_t i = stringPreis.find(",");
				if (i != std::string::npos)
				{
					stringPreis[i] = '.';
				}

				double preis = std::stod(stringPreis);
				
				const std::string einheit(zeile[2]);
				if (einheit == "Std." || einheit == "m²" || einheit == "m" || einheit == "m“")
				{
					continue;
				}

				m_MaterialListe.Hinzufügen(zeile[0], zeile[2], preis);
			}
			catch (const std::invalid_argument&)
			{
				continue;
			}
		}
	}
}

void Ausgangsrechnungen::DateiMaterialErstellen(const std::string& dateiName)
{
	m_MaterialListe.Sortieren();

	OfCsvDatei materialDatei(dateiName);
	for (size_t i = 0; i < m_MaterialListe.Size(); ++i)
	{
		const Material& material = m_MaterialListe.GetMaterial(i);

		std::stringstream ss;
		ss << std::fixed << std::setprecision(2) << material.Preis;
		std::string preis = ss.str();

		std::vector<std::string> vec = { material.Beschreibung, material.Einheit, preis };
		materialDatei.SetZeile(vec);
	}
}