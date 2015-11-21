#pragma once
#include"Data.h"

Data::Data(){
	cout << "Dziala konstruktor klasy Data bez argumentow\n";
	dzien = 1;
	miesiac = 1;
	rok = 1900;
}

Data::Data(int dz, int mi, int ro) :dzien(dz),
									miesiac(mi),
									rok(ro){
	cout << "Dziala konstruktor klasy Data z argumentami\n";
}

void Data::set_dzien(int dz){ dzien = dz; }
void Data::set_miesiac(int mi){ miesiac = mi; }
void Data::set_rok(int ro){ rok = ro; }

int Data::get_dzien(){ return dzien; }
int Data::get_miesiac(){ return miesiac; }
int Data::get_rok(){ return rok; }

