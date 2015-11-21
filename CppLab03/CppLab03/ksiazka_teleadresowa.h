#pragma once

#include<iostream>
#include"Data.h"
using namespace std;

class Ksiazka_teleadresowa{
	string Imie;
	string Nazwisko;
	Data data_urodzenia;
public:
	Ksiazka_teleadresowa();
	Ksiazka_teleadresowa(string im, string na, Data d_u);
	
	void set_imie(string im);
	void set_nazwisko(string na);
	void set_data_ur(Data d_u);
	void set_data_ur(int dz, int mi, int ro);

	string get_imie();
	string get_nazwisko();
	Data get_data_ur();

};