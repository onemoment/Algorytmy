#pragma once
#include <iostream>
#include "Adres.h"
#include "Data.h"
#include "Praca.h"

using namespace std;

Praca::Praca(){
	this->setNazwaFirmy("");
	this->setStanowisko("");
}

Praca::Praca(string NazwaFirmy){
	this->setNazwaFirmy(NazwaFirmy);
	this->setStanowisko("");
}

//setter
void Praca::setNazwaFirmy(string NazwaFirmy){ this->fNazwaFirmy = NazwaFirmy; }
void Praca::setStanowisko(string Stanowisko){ this->fStanowisko = Stanowisko; }

//getter
string Praca::getNazwaFirmy(){ return this->fNazwaFirmy; }
string Praca::getStanowisko(){ return this->fStanowisko; }
Adres Praca::getAdresFirmy(){ return this->fAdresFirmy; }
Data Praca::getDataZatrudnienia(){ return this->fDataZatrudnienia; }