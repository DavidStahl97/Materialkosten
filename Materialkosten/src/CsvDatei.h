#ifndef CSVDATEI_H
#define CSVDATEI_H

#include <string>
#include <vector>
#include <fstream>

/// <summary>
/// Mit der <see cref="IfCsvDatei"/>-Klasse liest man eine CSV-Datei.
/// </summary>
class IfCsvDatei
{
public:

	/// <summary>
	/// Ein Konstruktor von der <see cref="IfCsvDatei"/>-Klasse.
	/// </summary>
	/// <param name="Datei">Es ist der Name der Csv-Datei.</param>
	IfCsvDatei(const std::string& Datei);

	/// <summary>
	/// Diese Methode beurteilt, ob das Lesen der Datei im Moment geht. Man sollte das erst Checken, in dem man die Methode <see cref="Good"/>
	/// benutzt, damit es danach bei der Methode <seealso cref="GetZeile"/> kein Error gibt.
	/// </summary>
	/// <returns>
	/// Wenn das Lesen der Datei geht, gibt es als Rückgabewert true zurück.
	/// Wenn es aber den Namen der Datei gar nicht gibt oder die Zeilen sind bis zum Ende schon gelesen worden,
	/// dann gibt es als Rückgabewert false zurück.
	/// </returns>
	bool Good() const;

	/// <summary>
	/// <see cref="GetZeile"/> gibt alle Reihen der Zeile als Strings zurück.
	/// </summary>
	/// <param name="Zeile">Die Strings werden in einem Vektor zurück gegeben.</param>
	void GetZeile(std::vector<std::string>& Zeile);

private:

	/// <summary>
	/// Die <see cref="m_Quelle"/> wird benutzt, um die Datei zu lesen.
	/// </summary>
	std::ifstream m_Quelle;

};

/// <summary>
/// Mit der <see cref="OfCsvDatei"/>-Klasse schreibt man eine Csv-Datei.
/// </summary>
class OfCsvDatei
{
public:

	/// <summary>
	/// Ein Konstruktor von der <see cref="OfCsvDatei"/>-Klasse.
	/// </summary>
	/// <param name="Datei">Ein String für den Namen der Datei.</param>
	OfCsvDatei(const std::string& Datei);

	/// <summary>
	/// Bei dieser Methode wird eine komplette Zeile geschrieben.
	/// </summary>
	/// <param name="Zeile">Die Zeile wird mit einem Vector von Strings angegeben.</param>
	void SetZeile(const std::vector<std::string>& Zeile);

private:

	/// <summary>
	/// Die <see cref="m_Quelle"/> wird benuzt, um die Datei zu schreiben.
	/// </summary>
	std::ofstream m_Quelle;

};

#endif