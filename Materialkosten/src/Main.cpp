#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include "Ausgangsrechnungen.h"
 
// Mithilfe des LibreOffice-Programms ist es in der Lage ods in cvs zukonvertieren. Ods ist eine Zip-Datei.
/* 
   void Konvertieren(const std::string& datei, std::string& ordner)
   {
	  const std::string officeConsole("C:\\LibreOffice\\program\\soffice --headless --convert-to csv " + datei + " --outdir " + ordner);
	  system(officeConsole.c_str());
   }
 */

void MillisekundeAusgeben(long long millisekunde)
{
	std::string millisekundeString = std::to_string(millisekunde);
	std::cout << millisekundeString.substr(0, millisekundeString.size() - 3) << "."
		<< millisekundeString.substr(millisekundeString.size() - 3) << " sec";
}

long long AusgangsrechnungErstellen(const std::string& pfad, const std::string& ausgangsdatei)
{
	Ausgangsrechnungen ausgangsrechnungen;

	auto start = std::chrono::high_resolution_clock::now();
	ausgangsrechnungen.AlleMaterialienFinden(pfad);
	ausgangsrechnungen.DateiMaterialErstellen(ausgangsdatei);
	auto end = std::chrono::high_resolution_clock::now();

	auto differenz = end - start;
	long long millisekunde = std::chrono::duration_cast<std::chrono::milliseconds>(differenz).count();

	std::cout << std::endl << "Die Zeit, die gebraucht wurde: ";
	MillisekundeAusgeben(millisekunde);
	std::cout << std::endl;

	return millisekunde;
}

int main(int argc, char* argv[])
{
	int wiederholung = 1;
	if (argc == 4)
	{
		wiederholung = std::stoi(argv[3]);
	}
	else if (argc != 3)
	{
		std::cerr << "Gebrauch: Materialkosten.exe Pfad Ausgangsdatei" << std::endl;
		return 1;
	}

	long long summe = 0;
	for (int i = 0; i < wiederholung; ++i)
	{
		summe += AusgangsrechnungErstellen(argv[1], argv[2]);
		std::cout << std::endl;
	}
	summe /= wiederholung;

	std::cout << std::endl << "Das Erstellen der Ausgangsrechnung wurde " << wiederholung << " mal wiederholt." << std::endl
		<< "Durchschnitt: ";
	MillisekundeAusgeben(summe);
	std::cout << std::endl;

	return 0;
}