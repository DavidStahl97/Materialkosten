#include "CsvDatei.h"

namespace
{
	const char g_Komma = ',';
	const char g_Gänsefüsschen = '"';
}

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

	bool bisGänsefuss = false;
	std::string String;

	for (size_t i = 0; i < zeile.size(); ++i)
	{
		char c = zeile[i];

		if (c == g_Gänsefüsschen)
		{
			bisGänsefuss = !bisGänsefuss;
		}
		else if((c == g_Komma && !bisGänsefuss))
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

OfCsvDatei::OfCsvDatei(const std::string& Datei)
	: m_Quelle(Datei)
{
}

void OfCsvDatei::SetZeile(const std::vector<std::string>& Zeile)
{
	size_t i = 1;
	for (const std::string& p : Zeile)
	{
		if (p.find(g_Komma) != std::string::npos)
		{
			m_Quelle << g_Gänsefüsschen << p << g_Gänsefüsschen;
		}
		else
		{
			m_Quelle << p;
		}

		if (i < Zeile.size())
		{
			m_Quelle << g_Komma;
		}

		++i;
	}
	m_Quelle << std::endl;
}