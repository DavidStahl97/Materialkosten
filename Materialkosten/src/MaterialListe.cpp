#include "MaterialListe.h"

void MaterialListe::Hinzufügen(const std::string& beschreibung, const std::string einheit, double preis)
{
	for (size_t i = 0; i < m_MaterialListen.size(); ++i)
	{
		if (m_MaterialListen[i].Beschreibung == beschreibung)
		{
			m_MaterialListen[i].Preis = preis;
			return;
		}
	}

	m_MaterialListen.push_back(Material(beschreibung, einheit, preis));
}