#pragma once

#include"ksiazka_teleadresowa.h"

Ksiazka_teleadresowa::Ksiazka_teleadresowa(){
	cout << "Dziala konstruktor klasy KT bez argumentow\n";
	Imie = "Domyslne_imie";
	Nazwisko = "Domyslne_nazwisko";
//	data_urodzenia = Data();
}

Ksiazka_teleadresowa::Ksiazka_teleadresowa(string im, string na, Data d_u){
	cout << "Dziala konstruktor klasy KT z argumentami\n";
	Imie = im;
	Nazwisko = na;
	data_urodzenia = d_u;
}

void Ksiazka_teleadresowa::set_imie(string im){ Imie = im; }
void Ksiazka_teleadresowa::set_nazwisko(string na){ Nazwisko = na; }
void Ksiazka_teleadresowa::set_data_ur(Data d_u){ data_urodzenia = d_u; }
void Ksiazka_teleadresowa::set_data_ur(int dz, int mi, int ro){
	data_urodzenia = Data(dz, mi, ro);
}

string Ksiazka_teleadresowa::get_imie(){ return Imie; }
string Ksiazka_teleadresowa::get_nazwisko(){ return Nazwisko; }
Data Ksiazka_teleadresowa::get_data_ur(){ return data_urodzenia; }

