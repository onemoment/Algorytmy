#include <iostream>
#include <string>
#include"Data.h"
#include"ksiazka_teleadresowa.h"

using namespace std;

int main() {

	cout << "MENU\n";
	cout << "1. Wyswietl ksiazke adresowa\n";
	cout << "2. Dodaj element\n";

	int a;

	cin >> a;

	switch (a){
	case 1: cout << "Wybrales 1\n";
		break;
	case 2: cout << "Wybrales 2\n";
		break;
	default:
		cout << "Bledny wybor\n";
	}

	system("pause");
	return 0;
}
