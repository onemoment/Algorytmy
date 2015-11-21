#pragma once
#include <iostream>

using namespace std;

class Osoba{
	string fImie;
	string fNazwisko;
	char fPlec;

public:
	Osoba();
	Osoba(string Imie, string Nazwisko, char Plec);
	// getters
	string getImie();
	string getNazwisko();
	string getImieINazwisko(bool PierwszeImie);
	char getPlec();
	// setters
	void setImie(string Imie);
	void setNazwisko(string Nazwisko);
	void setPlec(char Plec);
};