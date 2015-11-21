#pragma once
#include<iostream>

using namespace std;

class Data{
	int dzien;
	int miesiac;
	int rok;
public:
	Data();
	Data(int dz, int mi, int ro);

	void set_dzien(int dz);
	void set_miesiac(int mi);
	void set_rok(int ro);
	
	int get_dzien();
	int get_miesiac();
	int get_rok();
};
