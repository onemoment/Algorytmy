#pragma once
#include <iostream>
#include <string>
#include "Data.h"


using namespace std;


Data::Data(): fDzien(1), fMiesiac(1), fRok(1900) {}

Data::Data(int Dzien, int Miesiac, int Rok){
	this->setRok(Rok);
	this->setMiesiac(Miesiac);
	this->setDzien(Dzien);	
}

// setters

void Data::setDzien(int Dzien){
	if (Dzien > 0 && Dzien < 32){
		this->fDzien = Dzien;
	}
	else
		this->fDzien = 1;
}


void Data::setMiesiac(int Miesiac){
	if (Miesiac > 0 && Miesiac < 13){
		this->fMiesiac = Miesiac;
	}
	else
		this->fMiesiac = 1;
}


void Data::setRok(int Rok){
	if (Rok >= 1900){
		this->fRok = Rok;
	}
	else
		this->fRok = 1900;
}


// getters

int Data::getDzien(){ return this->fDzien; }
int Data::getMiesiac(){ return this->fMiesiac; }
int Data::getRok(){ return this->fRok; }

string Data::getData(){
	string Result = "";
	int v = this->getDzien();

	if (v<10) Result.append("0");
	Result += to_string(static_cast<long long> (v) );
	Result += "-";

	v = this->getMiesiac();
	if (v<10) Result.append("0");
	Result += to_string(static_cast<long long> (v) );
	Result += "-";

	Result += to_string(static_cast<long long> (this->getRok()) );
	return Result;	
}