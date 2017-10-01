#ifndef MATERIALLISTE_H
#define MATERIALLISTE_H

#include <string>
#include <vector>
#include <algorithm>

/// <summary>
/// Eine Struktur namens <see cref="Material"/> beinhaltet alle n�tigen Objekts des Materials, die in der Ausgangsrechnung verarbeitet werden. 
/// </summary>
struct Material
{
public:

	/// <summary>
	/// Die Eigenschaft namens <see cref="Beschreibung/> ist der Name des Materials. 
	/// </summary>
	std::string Beschreibung;

	/// <summary>
	/// Die Eigenschaft namens <see cref="Einheit"/> ist die Einheit des Preises (wie z.B. Liter oder auch Meter).
	/// </summary>
	std::string Einheit;

	/// <summary>
	/// Die Eigenschaft namens <see cref="Preis"/> ist der Preis des Materials.
	/// </summary>
	double Preis;

	/// <summary>
	/// F�r den Konstruktor muss man die Eigenschaften des Materials �bergeben.
	/// </summary>
	Material(const std::string& beschreibung, const std::string& einheit, double preis)
		: Beschreibung(beschreibung), Einheit(einheit), Preis(preis)
	{
	}

};

/// <summary>
/// Eine Klasse ist eine Liste mit Materialien.
/// </summary>
class MaterialListe
{
public:

	/// <summary>
	/// Diese Methode f�gt ein Material in die Liste ein, wenn die Eigenschaft <see cref="beschreibung"/> nicht in der Liste schon gefunden wurde.
	/// </summary>
	/// <param name="beschreibung"><seealso cref="Material::Beschreibung"/></param>
	/// <param name="preis"><seealso cref="Material::Preis"/></param>
	/// <param name="einheit"><seealso cref="Material::Einheit"/></param>
	void Hinzuf�gen(const std::string& beschreibung, const std::string einheit, double preis);

	/// <summary>
	/// Gibt ein Material zur�ck.
	/// </summary>
	/// <param name="i">Die Methode braucht ein Parameter als Zahl, um das Material in der Liste zufinden.</param>
	/// <return>Gibt ein Material zur�ck, aber das zur�ckgegebene Material ist konstant.</return>
	inline const Material& GetMaterial(size_t i) const
	{
		return m_MaterialListen[i];
	}

	/// <summary>
	/// Die Methode namens <see cref="Sortieren"/> sortiert alle Materialien nach dem Alphabet.
	/// </summary>
	inline void Sortieren()
	{
		std::stable_sort(m_MaterialListen.begin(), m_MaterialListen.end(), [](const Material& e1, const Material& e2)
		{
			return e1.Beschreibung < e2.Beschreibung;
		});
	}

	/// <summary>
	/// Diese Methode gibt die Gr��e der Liste zur�ck.
	/// </summmary>
	/// <return>Die R�ckgabe gibt die Zahle zur�ck.</return>
	inline size_t Size() const
	{
		return m_MaterialListen.size();
	}

private:

	/// <summary>
	/// Die Eigenschaft namens <see cref="m_MaterialListen"/> ist ein Vektor.
	/// </summary>
	std::vector<Material> m_MaterialListen;
};

#endif