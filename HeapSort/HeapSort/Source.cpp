#include <iostream>
#include <time.h>

using namespace std;

void pokazTablice(string komunikat, int tablica[], int rozmiar);
void zamien(int i, int j, int tablica[]);
void doGory(int n, int tablica[]);
void naDol(int tablica[], int rozmiar);
void budujKopiec(int tablica[], int rozmiar);
void HeapSort(int tablica[], int rozmiar);

int main(){

	srand(time(0));
	int i;
	int rozm;
	
	cout << "Podaj rozmiar tablicy, n = ";
	cin >> rozm;

	int *wektor = new int[rozm];
	for (i=0; i<rozm; i++){
		wektor[i] = rand() % (100);
	}

	pokazTablice("Wylosowana tablica, T = ", wektor,rozm);
	
	HeapSort(wektor, rozm);
	
	pokazTablice("Posortowana tablica, T = ", wektor, rozm);

	system("PAUSE");
	return 0;
}


void pokazTablice(string komunikat, int tablica[], int rozmiar){
	if (rozmiar <= 20){
		cout << komunikat.c_str();
		for (int i=0; i<rozmiar; i++){
			cout << tablica[i] << ", ";
		} 
		cout << endl;
	}
}

void zamien(int i, int j, int tablica[]){
	int temp = tablica[i];
	tablica[i] = tablica[j];
	tablica[j] = temp;
}

void doGory(int n, int tablica[]){
	int ojciec = (n-1) / 2;
	int index = n;

	while (tablica[index] > tablica[ojciec]){
		zamien(ojciec, index, tablica);
		index = ojciec;
		ojciec = (index-1) / 2;
	}
}

void naDol(int tablica[], int rozmiar){

	for(int n = rozmiar-1; n > 0; n--){

		zamien(0, n, tablica);
	  
		int ptr = 0;
		int index; // wskazanie na ojca

		int lsyn = 0;
		int psyn = 0;

		while (ptr < n){

			index = ptr;

			// indeksy galezi drzewa
			lsyn = 2*index + 1;
			psyn = 2*index + 2;

			// okreslanie elementu do porownania
			if (lsyn >= n && psyn < n){
				ptr = psyn;
			}else if (lsyn < n && psyn >= n){
				ptr = lsyn;
			}else if (lsyn < n && psyn < n){
				tablica[lsyn] > tablica[psyn] ? ptr = lsyn : ptr = psyn;
			}else{
				break;
			}

			// zamieniamy jesli mniejszy
			if (tablica[index] < tablica[ptr]){
				zamien(index, ptr, tablica);
			}else{
				break;
			}
		}
		// while
	}// for
}

void budujKopiec(int tablica[], int rozmiar){
	for (int i=1; i<rozmiar; i++){
		doGory(i, tablica);
	}
}

void HeapSort(int tablica[], int rozmiar){
	budujKopiec(tablica, rozmiar);
	naDol(tablica, rozmiar);
}