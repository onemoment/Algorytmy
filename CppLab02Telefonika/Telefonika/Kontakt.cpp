#pragma once
#include <iostream>

#include "Osoba.h"
#include "Data.h"
#include "Telefon.h"
#include "Adres.h"
#include "Praca.h"
#include "Kontakt.h"

using namespace std;

Kontakt::Kontakt(){ 
	this->fMail = "";
}

/*
  Ustawia podstawowe dane kontaktu
*/
Kontakt::Kontakt(string Imie, string Nazwisko, string Telefon){
	this->fOsoba.setImie(Imie);
	this->fOsoba.setNazwisko(Nazwisko);
	this->fTelefon.setNumer(Telefon);
}

//getter
Osoba Kontakt::getOsoba(){ return this->fOsoba; }
Data Kontakt::getDataUrodzenia(){ return this->fDataUrodzenia; }
Telefon Kontakt::getTelefon(){ return this->fTelefon; }
Adres Kontakt::getAdres(){ return this->fAdres; }
Praca Kontakt::getPraca(){ return this->fPraca; }
string Kontakt::getMail(){ return this->fMail; }

//

void Kontakt::DrukujKontakt(){
	cout << "Kontakt:" << endl;
	// wypisanie danych osoby
	cout << this->getOsoba().getImieINazwisko(true).c_str() << endl;
	cout << "Plec: " << this->getOsoba().getPlec() << endl;
	cout << "Telefon: " << this->getTelefon().getTelefon().c_str() << endl;
	cout << "Adres e-mail: " << this->getMail().c_str() << endl;

	// wypisanie danych adresowych
	cout << endl;

	cout << "Adres: " << endl;
	cout << this->getAdres().getUlicaDom().c_str() << endl;
	cout << this->getAdres().getKodMiasto().c_str() << endl;
	cout << this->getAdres().getKraj().c_str() << endl;

	// wypisanie dannych dodatkowych
	cout << endl;

	cout << "Data urodzenia: " << this->getDataUrodzenia().getData().c_str() << endl;

	// wypisanie danych o pracy
	cout << endl;

	cout << "Praca: " << this->getPraca().getNazwaFirmy().c_str() << endl;
	cout << "Stanowisko: " << this->getPraca().getStanowisko().c_str() << endl;
	cout << "Zatrudniony od: " << this->getPraca().getDataZatrudnienia().getData().c_str() << endl;

	cout << "Adres siedziby: " << endl;
	cout << this->getPraca().getAdresFirmy().getUlicaDom().c_str() << endl;
	cout << this->getPraca().getAdresFirmy().getKodMiasto().c_str() << endl;
	cout << this->getPraca().getAdresFirmy().getKraj().c_str() << endl;
}