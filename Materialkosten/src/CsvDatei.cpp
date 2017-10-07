#include "CsvDatei.h"

#define KOMMA ','
#define GAENSEFUESCHEN '"'

IfCsvDatei::IfCsvDatei(const std::string& Datei)
	: m_Quelle(Datei)
{
}

bool IfCsvDatei::Good() const
{
	return m_Quelle.good();
}

void IfCsvDatei::GetZeile(std::vector<std::string>& Zeile)
{
	std::string zeile;
	getline(m_Quelle, zeile);

	bool bisG�nsefuss = false;
	std::string String;

	for (size_t i = 0; i < zeile.size(); ++i)
	{
		char c = zeile[i];

		if (c == GAENSEFUESCHEN)
		{
			bisG�nsefuss = !bisG�nsefuss;
		}
		else if((c == KOMMA && !bisG�nsefuss))
		{
			Zeile.push_back(String);
			String.clear();
		}
		else
		{
			String.push_back(c);
		}
	}

	Zeile.push_back(String);
}

std::string IfCsvDatei::NaechstesFeld(size_t naechsteReihe)
{
	std::string feld;
	bool gaensef�eschen = false;

	while (m_Quelle.good())
	{
		char buchstabe = m_Quelle.get();

		if (buchstabe == '\n')
		{
			return feld;
		}
		else if (buchstabe == KOMMA && !gaensef�eschen)
		{
			if (naechsteReihe == 0)
			{
				return feld;
			}

			--naechsteReihe;
		}
		else if (buchstabe == GAENSEFUESCHEN && naechsteReihe == 0)
		{
			gaensef�eschen = !gaensef�eschen;
		}
		else if(naechsteReihe == 0)
		{
			feld.push_back(buchstabe);
		}
	}

	return feld;
}

void IfCsvDatei::NaechsteReihe()
{
	while (m_Quelle.good() && m_Quelle.good() && m_Quelle.get() != '\n');
}

OfCsvDatei::OfCsvDatei(const std::string& Datei)
	: m_Quelle(Datei)
{
}

void OfCsvDatei::SetZeile(const std::vector<std::string>& Zeile)
{
	size_t i = 1;
	for (const std::string& p : Zeile)
	{
		if (p.find(KOMMA) != std::string::npos)
		{
			m_Quelle << GAENSEFUESCHEN << p << GAENSEFUESCHEN;
		}
		else
		{
			m_Quelle << p;
		}

		if (i < Zeile.size())
		{
			m_Quelle << KOMMA;
		}

		++i;
	}
	m_Quelle << std::endl;
}