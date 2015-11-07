#include <iostream>

using namespace std;

class Punkt{
	int x;
	int y;

public:
	// przeciazanie konstruktorow

	Punkt() : x(0), y(0) { // lista inicjalizacyjna
		cout << "Dziala konstruktor bez argumentow!" << endl;
	}

	Punkt(int a) : x(a), y(a) {} // jeden argument

	Punkt(int a, int b) : x(a), y(b) { 
		cout << "Dziala konstruktor z argumentami!" << endl; 
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

	// 'this' jest dla pól, nie dla metod wewnatrz klasy
};

void odleglosc(Punkt punkt);

int main(){

	//Punkt punkt; // z lista inicjalizacyjna
	Punkt punkt1; // zainocjowany w (0,0);
	cout << "Wartosc p1 (x, y) = (" << punkt1.get_x() << ", " << punkt1.get_y() << ") " << endl;
	cout << "Odleglosc od (0,0) = " << punkt1.odleglosc() << endl;


	// jeden argument
	int tmp;
	cout << "Podaj watosc dla kontruktora jednoargumentowego = ";
	cin >> tmp;
	Punkt punkt2(tmp);
	cout << "Wartosc p2 (x, y) = (" << punkt2.get_x() << ", " << punkt2.get_y() << ") " << endl;
	cout << "Odleglosc od (0,0) = " << punkt2.odleglosc() << endl;


	// z podanymi wartosciami
	int tmp2;
	cout << "Podaj wartosc x = ";
	cin >> tmp;
	cout << "Podaj wartosc y = ";
	cin >> tmp2;
	Punkt punkt3(tmp, tmp2);
	cout << "Wartosc p3 (x, y) = (" << punkt3.get_x() << ", " << punkt3.get_y() << ") " << endl;
	cout << "Odleglosc od (0,0) = " << punkt3.odleglosc() << endl;

	//cout << "Rozmiar obiektu punkt = " << sizeof(punkt) << "B" << endl;
	//cout << "Wartosc (x, y) = (" << punkt.get_x() << ", " << punkt.get_y() << ") " << endl;

	cout << "-- dla porownania funkcja zerwnetrzna daje ";
	odleglosc(punkt3);

	//cout << "Helo World" << endl; // :: - operator zakresu

	cout << endl;
	system("PAUSE");
	return 0;
}


void odleglosc(Punkt punkt){
	cout << sqrt(
		pow(punkt.get_x(), 2) + pow(punkt.get_y(), 2)
	);
}