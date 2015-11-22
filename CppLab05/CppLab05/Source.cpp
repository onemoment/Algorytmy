#pragma once

#include <iostream>
#include "Instrument.h"
#include "Trabka.h"
#include "Gitara.h"
#include "Fortepian.h"
#include "Elektryczna.h"

using namespace std;


void Zadzwiecz(Instrument &instrument);

int main(){

	Instrument instrument;
	Trabka trabka;
	Gitara gitara;
	Fortepian fortepian;
	Elektryczna elektryczna;

	instrument.wydajDzwiek();
	trabka.wydajDzwiek();
	gitara.wydajDzwiek();
	fortepian.wydajDzwiek();

	//

	Instrument *wskaznikNaInstrument;
	
	wskaznikNaInstrument = &instrument;
	wskaznikNaInstrument->wydajDzwiek();

	wskaznikNaInstrument = &trabka;
	wskaznikNaInstrument->wydajDzwiek();

	wskaznikNaInstrument = &gitara;
	wskaznikNaInstrument->wydajDzwiek();

	wskaznikNaInstrument = &fortepian;
	wskaznikNaInstrument->wydajDzwiek(); // dziala bo w Instrument jest virtual!

	wskaznikNaInstrument = &elektryczna;
	wskaznikNaInstrument->wydajDzwiek();

	Zadzwiecz(trabka);
	//
	cout << endl << endl;
	system("PAUSE");
	return 0;
}


void Zadzwiecz(Instrument &instrument){
	instrument.wydajDzwiek();
}