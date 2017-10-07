#ifndef MATERIALLISTE_H
#define MATERIALLISTE_H

#include <string>
#include <vector>
#include <algorithm>

struct Material
{
public:
	std::string Beschreibung;
	std::string Einheit;
	double Preis;

	Material(const std::string& beschreibung, const std::string& einheit, double preis)
		: Beschreibung(beschreibung), Einheit(einheit), Preis(preis)
	{
	}
};

class MaterialListe
{
public:
	void Hinzufügen(const std::string& beschreibung, const std::string einheit, double preis);

	inline const Material& GetMaterial(size_t i) const
	{
		return m_MaterialListen[i];
	}

	inline void Sortieren()
	{
		std::stable_sort(m_MaterialListen.begin(), m_MaterialListen.end(), [](const Material& e1, const Material& e2)
		{
			return e1.Beschreibung < e2.Beschreibung;
		});
	}

	inline size_t Size() const
	{
		return m_MaterialListen.size();
	}

private:
	std::vector<Material> m_MaterialListen;
};

#endif