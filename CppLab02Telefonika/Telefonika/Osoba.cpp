#pragma once
#include "Osoba.h"

/*
  plec:
  N- nieokreslone
  K- kobieta
  M- mezczyzna
*/
Osoba::Osoba(){
	this->fImie = "";
	this->fNazwisko = "";
	this->fPlec = 'N'; 
}

Osoba::Osoba(string Imie, string Nazwisko, char Plec){
	this->setImie(Imie);
	this->setNazwisko(Nazwisko);
	this->setPlec(Plec);
}

// getters

string Osoba::getImie(){ return this->fImie; }
string Osoba::getNazwisko(){ return this->fNazwisko; }
string Osoba::getImieINazwisko(bool PierwszeImie){
	string Result;
	if (PierwszeImie)
		Result = this->getImie().append(" ") += this->getNazwisko(); else
		Result = this->getNazwisko().append(" ") += this->getImie();

	return Result;
}
char Osoba::getPlec(){ return this->fPlec; }

// setters

void Osoba::setImie(string Imie){
	this->fImie = Imie;
}

void Osoba::setNazwisko(string Nazwisko){
	this->fNazwisko = Nazwisko;
}

void Osoba::setPlec(char Plec){
	if (Plec == 'K' || Plec == 'M')
		this->fPlec = Plec; else
		this->fPlec = 'N';
}