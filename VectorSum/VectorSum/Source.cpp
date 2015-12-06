#include <iostream>

using namespace std;

int max(int one, int two);

int main(){

	int wektor[] = { 31, -41, 59, 26, -53, 58, 97, 93, -23, 84 };
	//int wektor[] = { -3, 2, -5, 6, 7, -10, -12, -8, -7, 20 };

	int oldMaxHere = 0;
	int oldMaxSoFar = 0;

	int maxSoFar = 0;
	int maxHere = 0;

	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < 10; i++){

		// poprzedni stan
		oldMaxHere = maxHere;
		oldMaxSoFar = maxSoFar;

		// obliczenia
		maxHere = max(maxHere + wektor[i], 0);
		maxSoFar = max(maxSoFar, maxHere);

		// okreslanie indeksow
		if (oldMaxHere == 0 && maxHere > 0 && oldMaxSoFar < maxSoFar) {
			index1 = i;
		}

		if (oldMaxSoFar < maxSoFar){
			index2 = i;
		}
	}

	// wyswietlenie
	cout << maxSoFar << " dla przedzialu [ " << index1 << ", " << index2 << " ]" << endl;


	cout << endl;
	system("PAUSE");
	return 0;
}

int max(int one, int two){
	if (one > two)
		return one;
	return two;
}

/*
algorytm liniowy
nalezy dopisac indeksy w których jest zawarta najwieksza suma
*/