#include <iostream>

using namespace std;

void zmiana(int i, int j, int table[]){
	int temp = table[i];
	table[i] = table[j];
	table[j] = temp;
}

void rewers(int table[], int rozmiar){
	int srodek = rozmiar / 2;

	for (int i=0; i<srodek; i++){
		zmiana(i,rozmiar-i-1,table);
	}
}


void doGory(int n, int table[]){

	int ojc = (n-1) / 2;
	int index = n;

	
	while (table[index] < table[ojc]){

		zmiana(ojc, index, table);
		index = ojc;
		ojc = (index-1) / 2;
	}
}



void kopiec(int table[], int rozmiar){
	for (int i=1; i<rozmiar; i++){
		doGory(i,table);
	}
}

void naDol(int table[], int rozmiar){

	for(int i=rozmiar-1; i>0; i--){
	  zmiana(0,i, table);
	  kopiec(table,i);
	}

}

void kopcuj(int table[], int rozmiar){
	kopiec(table, rozmiar);
	naDol(table,rozmiar);
	rewers(table, rozmiar);
}
int main(){

	int i;

	int rozm = 7;
	//int wektor[] = { 12, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19 };
	int wektor[] = {5,6,7,1,2,0,3};
	for (i=0;i<rozm;i++){cout << wektor[i] << ", ";} cout << endl;
	kopcuj(wektor, rozm);
	for (i=0;i<rozm;i++){cout << wektor[i] << ", ";} cout << endl;
	system("PAUSE");
	return 0;
}



/*
korzeñ= 1
wartoœæ(i)  =x[i]
lewysyn(i)  = 2*i
prawysyn(i) = 2*i+1
ojciec(i)   =i div 2
*/