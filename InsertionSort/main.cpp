#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

double silnia_v1(int);
double silnia_v2(int);

void swap_t(int *tab, int a, int b);
void printTable(int *tab, int n);
void insetrionSort(int *tab, int n);

int main(){

	// **************
	// Silnia
	// **************
	/*
	int n;
	cout << "Podaj liczbe n = ";
	cin >> n;

	cout << "v1 : " << n << "! = " << silnia_v1(n) << endl;
	cout << "v2 : " << n << "! = " << silnia_v2(n) << endl;

	for (int licznik = 0; licznik <= 55; licznik++){
		printf("%74.0f=%2d!\n", silnia_v2(licznik), licznik);
	}
	*/

	// **************
	// Sortowanie przez podstawianie
	// **************

	srand(time(0));

	int n;
	cout << "Podaj rozmiar tablicy n = ";
	cin >> n;

	time_t t1;
	time_t t2;
	
	int *t = new int[n];
	//t = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		t[i] = rand() % 100;
	
	time(&t1);
	//printTable(t, n);
	insetrionSort(t, n);
	//printTable(t, n);
	time(&t2);

	cout << "czas wykonania = " << t2 - t1 << "sek. " << endl;
	delete t;

	//
	system("pause");
	return 0;
}


double silnia_v1(int liczba){
	if (liczba == 0){
		return 1;
	}
	else{
		double res = 1.0;
		for (int i = 1; i <= liczba; i++)
			res *= i;
		return res;
	}
}


double silnia_v2(int liczba){
	if (liczba == 0){
		return 1.0;
	}
	else{
		return silnia_v2(liczba-1) * liczba;
	}
}


void swap_t(int *tab, int a, int b){
	int tmp;
	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}


void printTable(int *tab, int n){
	cout << "Tablica: " << endl;
	for (int i = 0; i < n; i++)
		cout << "t[" << i << "] = " << tab[i] << endl;
}


void insetrionSort(int *tab, int n){
	for (int i = 1; i < n; i++){
		for (int j = i; j >= 1; j--){
			if (tab[j] < tab[j - 1]){
				swap_t(tab, j, j - 1);
			}
		}
	}
}