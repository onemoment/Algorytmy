#include <iostream>
#include <time.h>

using namespace std;

double Rand01();

int main(){

	srand(time(0));

	int m, n;

	cout << "Podaj zakres danych, n = ";
	cin >> n;

	cout << "Podaj ilosc losowanych liczb, m = ";
	cin >> m;

	int *T = new int[n];
	for (int i = 0; i < n; i++){ T[i] = i + 1; }

	int sel, rem;
	double prob, random;

	sel = m;
	rem = n;
	prob = 0.0;

	if (m > n){
		cout << "Niepoprawne dane." << endl;
	}
	else {
		for (int i = 0; i < n; i++){
			prob = (double)sel / (double)rem;
			random = Rand01();

			if (random < prob){
				sel--;
				cout << "-> " << T[i] << "  wybrano.   P=" << prob << "   R=" << random << endl;
			}
			rem--;
		}
	}

	cout << endl;
	system("PAUSE");
}


double Rand01(){
	return (double)rand() / (double)(RAND_MAX + 1);
}