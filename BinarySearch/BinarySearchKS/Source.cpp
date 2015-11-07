#include <iostream>
#include <time.h>

using namespace std;

int BinarySearch(int *Tab, int start, int end, int needle);
double Rand01();
void GenerujTablice(int *Tab, int rozmiar);

int main(){

	srand(time(0));
	int n;
	cout << "Podaj ilosc elementow tablicy, n = ";
	cin >> n;

	int *T = new int[n];
	GenerujTablice(T, n); // test losowy
	cout << endl << "[";
	for (int i = 0; i < n; i++){
		cout << T[i];
		if (i < n-1){
			cout << ",";
		}
		
	}
	cout << "]" << "\n\n";

	int p;
	cout << "Podaj liczbe do wyszukania, p = ";
	cin >> p;

	int wynik;
	wynik = BinarySearch(T, 0, n, p);
	if (wynik >= 0){
		cout << p << " jest na pozycji " << wynik+1 << "\n\n";
	}
	else{
		cout << p << " nie znajduje sie w tablicy.\n\n";
	}
	system("PAUSE");
}

int BinarySearch(int *Tab, int start, int end, int needle){
	int cntr = 0;

	while (start < end){
		cntr = (start + end) / 2;

		if (Tab[cntr] < needle){ start = cntr + 1; } 
		else if (Tab[cntr] == needle){ return cntr; }
		else if (Tab[cntr] > needle){ end = cntr - 1; }
	}

	return -1;
}

double Rand01(){
	return (double)rand() / (double)(RAND_MAX + 1);
}

void GenerujTablice(int *Tab, int rozmiar){

	int przedzial = rozmiar * 10;
	int sel, rem, indeks;
	double prob, random;

	sel = rozmiar;
	rem = przedzial;
	indeks = 0;
	prob = 0.0;

	for (int i = 0; i < przedzial; i++){
		prob = (double)sel / (double)rem;
		random = Rand01();

		if (random < prob){
			sel--;
			Tab[indeks] = i+1;
			indeks++;
		}
		rem--;
	}

}