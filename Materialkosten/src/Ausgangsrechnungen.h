#ifndef MATERIALRECHNUNGEN_H
#define MATERIALRECHNUNGEN_H

#include "MaterialListe.h"

class Ausgangsrechnungen
{
public:
	void AlleMaterialienFinden(const std::string& ordner);
	void DateiMaterialErstellen(const std::string& dateiName);

private:
	void MaterialFinden(const std::string& datei);

private:
	MaterialListe m_MaterialListe;
};

#endif