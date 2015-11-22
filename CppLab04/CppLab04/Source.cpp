#pragma once

#include <iostream>
#include <string>

#include "Header.h"

using namespace std;

class Punkt: public Output{
protected:

	int x;
	int y;

public:

	Punkt() : x(0), y(0) {
		cout << "Dziala konstruktor bez argumentow! Punkt." << endl;
	}

	Punkt(int a) : x(a), y(a) {} // jeden argument

	Punkt(int a, int b) : x(a), y(b) {
		cout << "Dziala konstruktor z argumentami!" << endl;
	}

	~Punkt(){
		cout << "Dziala destruktor klasy Punkt." << x << y << endl;
	}

	// gettery

	int get_x(){ return this->x; }
	int get_y(){ return this->y; }

	// settery
	void set_x(int xx){ this->x = xx; }
	void set_y(int yy){ this->y = yy; }

	// zwraca odleglosc od poczatku ukladu wspolrzednych
	float odleglosc(){
		return sqrt(
			pow(this->x, 2) + pow(this->y, 2)
			);
	}
};

class KolorowyPunkt: public Punkt{
	string Kolor;
public:
	// nie dziedziczymy konstruktorów

	// lista inicjalizacyjna odnosi sie tylko do obiektow danej klasy
	KolorowyPunkt() : Kolor("bialy"){ cout << "Dziala konstruktor bez argumentow! KolorowyPunkt." << endl; }

	KolorowyPunkt(string aKolor) : Kolor(aKolor){
		cout << "Dziala konstruktor z argumentem! KolorowyPunkt." << endl; 
	}

	KolorowyPunkt(int a, int b, string aKolor): Punkt(a,b), Kolor(aKolor){} // <- :)

	KolorowyPunkt(Punkt xy, string kolor): Kolor(kolor){
		x = xy.get_x();
		y = xy.get_y();
		cout << "Dziala konstruktor z dwoma argumentem! KolorowyPunkt." << endl;
	}

	void setKolor(string aKolor){
		Kolor = aKolor;
	}

	string getKolor(){
		return Kolor;
	}
};



int main(){

	{
		KolorowyPunkt kp;

		cout << kp.get_x() << ", " << kp.get_y() << ", " << kp.getKolor() << endl;

		Punkt jakis(3, 4);
		
		cout << "test";
		jakis.~Punkt();
		jakis = NULL;
		cout << "test2";

		KolorowyPunkt np = KolorowyPunkt(jakis, "kolor"); // po zniszczeniu obiektu
		
		cout << np.get_x() << ", " << np.get_y() << ", " << np.getKolor() << endl;

		np.wyswietl(np.get_x(), np.get_y());
		jakis.wyswietl(jakis.get_x(), jakis.get_y());
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}