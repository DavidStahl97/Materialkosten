#ifndef CSVDATEI_H
#define CSVDATEI_H

#include <string>
#include <vector>
#include <fstream>

class IfCsvDatei
{
public:
	IfCsvDatei(const std::string& Datei);

	bool Good() const;
	std::string NaechstesFeld(size_t naechsteReihe = 0);
	void NaechsteReihe();

	//deprecated
	void GetZeile(std::vector<std::string>& Zeile);
private:
	std::ifstream m_Quelle;
};

class OfCsvDatei
{
public:
	OfCsvDatei(const std::string& Datei);

	void SetZeile(const std::vector<std::string>& Zeile);

private:
	std::ofstream m_Quelle;
};

#endif