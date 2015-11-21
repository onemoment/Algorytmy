#pragma once
#include <iostream>
#include <string>
#include "Kontakt.h"

using namespace std;

int main(){

	int wybor;
	string aImie;
	string aNazwisko;
	string aTelefon;
	string aDaneStr;
	int aDaneInt;

	cout << endl;

	cout << "Imie: ";
	cin >> aImie;

	cout << "Nazwisko: ";
	cin >> aNazwisko;

	cout << "Numer telefonu: ";
	cin >> aTelefon;

	//Kontakt kontakt;
	Kontakt kontakt(aImie,aNazwisko, aTelefon);
	//kontakt.getOsoba().setImie(aImie);//, aNazwisko, aTelefon);

	do{
		cout << "Wybierz opcje: " << endl;
		cout << "1 - Uzupelnij adres" << endl;
		cout << "2 - Uzupelnij mail" << endl;
		cout << "3 - Uzupelnij plec" << endl;
		cout << "4 - Uzupelnij dane zatrudnienia" << endl;

		cout << "9 - Wyswietl kontakt" << endl;
		cout << "0 - Zakoncz" << endl;

		cin >> wybor;

		switch(wybor){
		case 0: break;
		case 1:
			cout << endl;
			cout << "Ulica: ";
			cin >> aDaneStr; kontakt.getAdres().setUlica(aDaneStr);

			cout << "Numer domu: ";
			cin >> aDaneStr; kontakt.getAdres().setDom(aDaneStr);

			cout << "Numer mieszkania (0 jesli brak): ";
			cin >> aDaneInt; kontakt.getAdres().setMieszkanie(aDaneInt);

			cout << "Kod pocztowy (bez kresek): ";
			cin >> aDaneInt; kontakt.getAdres().setKod(aDaneInt);

			cout << "Miejscowosc: ";
			cin >> aDaneStr; kontakt.getAdres().setMiasto(aDaneStr);

			cout << "Kraj (jesli Polska to mozna wpisac - ): ";
			cin >> aDaneStr; 
			if (aDaneStr.compare("-") == 0)
				kontakt.getAdres().setKraj("POLSKA"); else
				kontakt.getAdres().setKraj(aDaneStr);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 9:
			kontakt.DrukujKontakt();
			break;
		default:
			cout << "Niepoprawny wybor, sprobuj jeszcze raz."<< endl;
		}
		
	}while(wybor != 0);

	//system("PAUSE");
	return 0;
}

/*
Kontakt()

* osoba{imie i nazwisko, p³eæ} Osoba()
* data urodzenia {dzien miesiac rok} Data()
* telefon {prefix, numer} Telefon()
* adres{ulica, numer domu, kod pocztowy, miatso, pañstwo} Adres()
praca{nazwa firmy, stanowisko, adres, data zatrudnienia} Praca()
mail

*/

