#include <iostream>
#include <string>
#include"Data.h"
#include"ksiazka_teleadresowa.h"

using namespace std;

void PokazTeleadres(Ksiazka_teleadresowa T);
void PokazKsiazke(Ksiazka_teleadresowa *K, int Rozmiar);

void DodajElement(Ksiazka_teleadresowa *K, int Rozmiar);

int main() {

	int a;
	Ksiazka_teleadresowa tab_el[3];

	do{

		cout << "MENU\n";
		cout << "1. Wyswietl ksiazke adresowa\n";
		cout << "2. Dodaj element\n";
		cout << "0. Wyjscie\n";

		cin >> a;

		switch (a){
		case 0: break;
		case 1: PokazKsiazke(tab_el, 3);
			break;

		case 2: DodajElement(tab_el, 3);
			break;
		default:
			cout << "Bledny wybor\n";
		}

	} while (a > 0);

	return 0;
}


void PokazTeleadres(Ksiazka_teleadresowa T){
	cout << "Osoba: " << T.get_imie() << " " << T.get_nazwisko() << endl;
	cout << "Data urodzenia: ";
	cout << T.get_data_ur().get_dzien() << "-" << T.get_data_ur().get_miesiac() << "-" << T.get_data_ur().get_rok();
	cout << endl;
}

void PokazKsiazke(Ksiazka_teleadresowa *K, int Rozmiar){
	cout << "Ksiazka teleadresowa::" << endl;
	for (int i = 0; i < Rozmiar; i++){
		cout << "Kontakt " << i+1 << ": " << endl;
		PokazTeleadres(K[i]);
	}
}

void DodajElement(Ksiazka_teleadresowa *K, int Rozmiar){
	cout << "Wskaz, w ktorym miejscu chcesz dodac kontakt, i = ";
	int index;

	string aString;
	int aDzien, aMiesiac, aRok;

	cin >> index;

	if (index > Rozmiar || index < 1){
		cout << "No chyba nie.. Brak takiego elementu.";
	}
	else {

		index--;

		cout << "Imie: "; cin >> aString; K[index].set_imie(aString);
		cout << "Nazwisko: "; cin >> aString; K[index].set_nazwisko(aString);

		cout << "Data urodzenia:" << endl;

		cout << "Dzien: "; cin >> aDzien;
		cout << "Miesiac: "; cin >> aMiesiac; 
		cout << "Rok: "; cin >> aRok; 

		K[index].set_data_ur(aDzien, aMiesiac, aRok);
	}
}
/*
wyswietl ksiazke
dodaj element
usun element
edytuj element
wyjscie
*/
