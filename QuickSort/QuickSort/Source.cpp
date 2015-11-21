#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void printTable(int *tab, int n);
void swap(int index1, int index2, int *T);
void quickSort2(int start, int end, int *T);
void quickSort(int start, int end, int *T);

int main(){
	
	srand(time(0));

	int n;
	cout << "Podaj rozmiar zablicy n = ";
	cin >> n;

	int *T = new int[n];

	for (int i = 0; i < n; i++){
		//T[i] = rand() % 1000;
		//T[i] = (i + 1);
		T[i] = (i+1) % 10;
		//T[i] = 1;
		//T[i] = n - i;
	}

	//int T[10] = { 5, 7, 2, 8, 4, 1, 9, 6, 3, 0 };
	//int T[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int T[10] = { 1,1,1,1,1,1,1,1,1,1 };

	if (n <= 100) printTable(T, n);
	quickSort2(0, n-1, T);
	if (n <= 100) printTable(T, n);

	delete T;

	system("PAUSE");
	return 0;
}

void swap(int index1, int index2, int *T){
	if (index1 != index2){
		int temp = T[index1];
		T[index1] = T[index2];
		T[index2] = temp;
	}
}

void quickSort2(int start, int end, int *T){

	if (end > start){
		int border = T[start];
		int center = start;

		bool ok = false;

		for (int i = start+1; i <= end; i++){
			if (T[i - 1] > T[i]){
				ok = true;
				break;
			}
		}

		if (ok){

			for (int i = start + 1; i <= end; i++){
				if (T[i] < border){
					center++;
					swap(center, i, T);
				}
			}
			swap(start, center, T);
			quickSort2(start, center - 1, T);
			quickSort2(center + 1, end, T);

		}
	}
}

void quickSort(int start, int end, int *T){

	if (end > start){
		int border = T[start];
		int center = start;

		for (int i = start + 1; i <= end; i++){
			if (T[i] < border){
				center++;
				swap(center, i, T);
			}
		}
		swap(start, center, T);

		quickSort(start, center - 1, T);
		quickSort(center + 1, end, T);
	}
}

void printTable(int *tab, int n){
	cout << "Tablica: " << endl;
	for (int i = 0; i < n; i++){
		if (i == 0)
			cout << "t[" << i << "] = " << tab[i] << endl; else
			cout << "t[" << i << "] = " << tab[i] << endl;
	}
	cout << endl;
}

/*
1. zwykly qs
a. n = 100  z wyswietlaniem
b. n = 100 000 bez wyswietlania
c. n = 1 000 000 -//-

d. n = 100 000 od 1..100 000
2. optymalizacja algorytmu do dzia³ania na tablicach ju¿ posortowanych
*/