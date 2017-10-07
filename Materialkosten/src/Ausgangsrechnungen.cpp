#include "Ausgangsrechnungen.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include "CsvDatei.h"
#include "Common.h"

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
			try
			{
				const std::string beschreibung(quelle.NaechstesFeld());

				const std::string menge(quelle.NaechstesFeld());
				std::stod(menge);

				const std::string einheit(quelle.NaechstesFeld());

				std::string stringPreis(quelle.NaechstesFeld());
				size_t i = stringPreis.find(",");
				if (i != std::string::npos)
				{
					stringPreis[i] = '.';
				}
				double preis = std::stod(stringPreis);

				const std::string gesamtpreis(quelle.NaechstesFeld());
				std::stod(gesamtpreis);
				if (einheit == "Std." || einheit == "m²" || einheit == "m" || einheit == "m“")
				{
					quelle.NaechsteReihe();
					continue;
				}

				m_MaterialListe.Hinzufügen(beschreibung, einheit, preis);
			}
			catch (const std::invalid_argument&)
			{
				quelle.NaechsteReihe();
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