#pragma once
#include <iostream>
#include "Telefon.h"

using namespace std;

Telefon::Telefon(): fPrefix("+00"), fNumer("000000000") {}

Telefon::Telefon(string Numer){
	this->setNumer(Numer);
}

Telefon::Telefon(string Prefix, string Numer){
	this->setNumer(Prefix, Numer);
}

// setter

void Telefon::setNumer(string Prefix, string Numer){
	this->fPrefix = Prefix;
	this->fNumer = Numer;
}

void Telefon::setNumer(string Numer){
	switch( Numer.length() ){
	case 9:
		this->setNumer("+00", Numer);
		break;
	case 13:
		this->setNumer(
			Numer.substr(0,3),
			Numer.substr(4,9)
		);
		break;
	default:
		this->setNumer("+00", "000000000");
	}
}

// getter

string Telefon::getPrefix(){ return this->fPrefix; }
string Telefon::getNumer(){ return this->fNumer; }
string Telefon::getTelefon(){
	return this->getPrefix().append(" ") += this->getNumer();
}