#include <iostream>
#include <string>
#include"Data.h"
#include"ksiazka_teleadresowa.h"

using namespace std;

enum Tryb{
	trybEdycja,
	trybDodaj,
	trybUsun
};

void PokazTeleadres(Ksiazka_teleadresowa T);
void PokazKsiazke(Ksiazka_teleadresowa *K, int Rozmiar);

void ZmienElement(Ksiazka_teleadresowa *K, int Index, Tryb tryb, int dane);
void RejestracjaObiektu(Ksiazka_teleadresowa *K, int Rozmiar, Tryb tryb);

int main() {

	int a;
	Ksiazka_teleadresowa tab_el[3];

	do{

		cout << "MENU\n";
		cout << "1. Wyswietl ksiazke adresowa\n";
		cout << "2. Dodaj element\n";
		cout << "3. Usun element\n";
		cout << "4. Edytuj element\n";
		cout << "0. Wyjscie\n";

		cin >> a;

		switch (a){
		case 0: break;
		case 1: PokazKsiazke(tab_el, 3);
			break;

		case 2: RejestracjaObiektu(tab_el, 3, trybDodaj);
			break;

		case 3: RejestracjaObiektu(tab_el, 3, trybUsun);
			break;

		case 4: RejestracjaObiektu(tab_el, 3, trybEdycja);
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

void ZmienElement(Ksiazka_teleadresowa *K, int Index, Tryb tryb, int dane){
	string aString, aDodatekA, aDodatekB, aDodatekC;
	int aDzien, aMiesiac, aRok;

	if (tryb == trybUsun){
		K[Index] = Ksiazka_teleadresowa();
	}
	else {
		bool czyEdycja = tryb == trybEdycja;

		if (czyEdycja){
			aDodatekA = "Nowe ";
			aDodatekB = "Nowa ";
			aDodatekC = "Nowy ";
		}
		else{
			aDodatekA = "";
			aDodatekB = "";
			aDodatekC = "";
		}

		if (!czyEdycja || dane == 1) { cout << aDodatekA << "Imie: "; cin >> aString; K[Index].set_imie(aString); }
		if (!czyEdycja || dane == 2) { cout << aDodatekA << "Nazwisko: "; cin >> aString; K[Index].set_nazwisko(aString); }
		if (!czyEdycja || dane == 3) {
			cout << aDodatekB << "Data urodzenia:" << endl;
			cout << aDodatekC << "Dzien: "; cin >> aDzien;
			cout << aDodatekC << "Miesiac: "; cin >> aMiesiac;
			cout << aDodatekC << "Rok: "; cin >> aRok;
			K[Index].set_data_ur(aDzien, aMiesiac, aRok);
		}
	}
}

void RejestracjaObiektu(Ksiazka_teleadresowa *K, int Rozmiar, Tryb tryb){

	int index;
	int wybor;

	switch (tryb)
	{
	case trybDodaj:
		cout << "Wskaz, w ktorym miejscu chcesz dodac kontakt, i = ";
		cin >> index;
		wybor = 0;
		break;

	case trybEdycja:
		cout << "Wskaz, w ktorym miejscu chcesz dodac kontakt, i = ";
		cin >> index;
		cout << "Podaj, jakie dane chcesz edytowac:\n1. Imie\n2. Nazwisko\n3. DataUrodzenia\n";
		cin >> wybor;
		break;

	case trybUsun:
		cout << "Wskaz, ktory kontakt chcesz usunac, i = ";
		cin >> index;
		wybor = 0;
		break;

	default:
		break;
	}


	
	if (index > Rozmiar || index < 1){
		cout << "Brak takiego elementu.";
	}
	else {
		index--;
		ZmienElement(K, index, tryb, wybor);
	}
}
/*
wyswietl ksiazke
dodaj element
usun element
edytuj element
wyjscie
*/
