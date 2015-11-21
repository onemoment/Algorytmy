#pragma once
#include <iostream>

#include "Osoba.h"
#include "Data.h"
#include "Telefon.h"
#include "Adres.h"
#include "Praca.h"

using namespace std;

class Kontakt{
	Osoba fOsoba;
	Data fDataUrodzenia;
	Telefon fTelefon;
	Adres fAdres;
	Praca fPraca;
	string fMail;
public:
	Kontakt();
	Kontakt(string Imie, string Nazwisko, string Telefon);
	//getter
	Osoba getOsoba();
	Data getDataUrodzenia();
	Telefon getTelefon();
	Adres getAdres();
	Praca getPraca();
	string getMail();
	//
	void DrukujKontakt();
};