#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void printTable(int *tab, int n);
void swap(int index1, int index2, int *T);
void quickSort(int start, int end, int *T);

int main(){
	
	srand(time(0));

	int n;
	cout << "Podaj rozmiar zablicy n = ";
	cin >> n;

	int *T = new int[n];

	for (int i = 0; i < n; i++){
		T[i] = rand() % 1000;
	}

	//int T[10] = { 5, 7, 2, 8, 4, 1, 9, 6, 3, 0 };
	//int T[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int T[10] = { 1,1,1,1,1,1,1,1,1,1 };

	printTable(T, n);
	quickSort(0, n-1, T);
	printTable(T, n);

	delete T;

	system("PAUSE");
	return 0;
}

void swap(int index1, int index2, int *T){
	int temp = T[index1];
	T[index1] = T[index2];
	T[index2] = temp;
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
	for (int i = 0; i < n; i++)
		cout << "t[" << i << "] = " << tab[i] << endl;
}

/*
1. zwykly qs
2. optymalizacja algorytmu do dzia³ania na tablicach ju¿ posortowanych
*/