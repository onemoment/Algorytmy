#pragma once
#include <iostream>

using namespace std;

class Telefon{
	string fPrefix;
	string fNumer;
public:
	Telefon();
	Telefon(string Numer);
	Telefon(string Prefix, string Numer);
	// setter
	void setNumer(string Prefix, string Numer);
	void setNumer(string Numer);

	// getter
	string getPrefix();
	string getNumer();
	string getTelefon();

};