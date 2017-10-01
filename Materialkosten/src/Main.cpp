#include <string>
#include "Ausgangsrechnungen.h"

/*void Konvertieren(const std::string& datei, std::string& ordner)
{
	const std::string csvOrdner("./CSV");
	for (auto& p : std::experimental::filesystem::directory_iterator(csvOrdner))
	{
		std::string odsDatei = datei.substr(6, )
	}



	const std::string officeConsole = "C:\\LibreOffice\\program\\soffice --headless --convert-to csv " + datei + " --outdir " + ordner;
	system(officeConsole.c_str());
}*/

int main()
{
	const std::string ordner("./CSV");
	const std::string materialListeDatei("Material.csv");
	
	Ausgangsrechnungen ausgangsrechnungen;
	ausgangsrechnungen.AlleMaterialienFinden(ordner);
	ausgangsrechnungen.DateiMaterialErstellen(materialListeDatei);

	return 0;
}