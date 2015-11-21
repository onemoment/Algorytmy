#pragma once
#include <iostream>
#include "Adres.h"
#include "Data.h"

using namespace std;

class Praca{
	string fNazwaFirmy;
	string fStanowisko;
	Adres fAdresFirmy;
	Data fDataZatrudnienia;
public:
	Praca();
	Praca(string NazwaFirmy);
	//setter
	void setNazwaFirmy(string NazwaFirmy);
	void setStanowisko(string Stanowisko);
	//getter
	string getNazwaFirmy();
	string getStanowisko();
	Adres getAdresFirmy();
	Data getDataZatrudnienia();
};