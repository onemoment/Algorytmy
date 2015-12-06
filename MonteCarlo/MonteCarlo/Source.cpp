#include <iostream>
#include <time.h>

using namespace std;

double f(double x);
double S(double a, double b, int n);

int main(){
	srand(time(0));

	double a, b;
	int n;

	cout << "Podaj poczatek przedzialu calkowania, a = ";
	cin >> a;

	cout << "Podaj koniec przedzialu calkowania, b = ";
	cin >> b;

	cout << "Podaj licznik losowan, n = ";
	cin >> n;

	cout << S(a, b, n) << endl;

	system("PAUSE");
}


double f(double x){
	return x * x - 5 * x + 3;
	//return 2 * x - 5;
}

double S(double a, double b, int n){
	double Xlos;
	double stala = (b - a) / n;
	double suma = 0;
	double fx;

	int aa, bb;
	aa = (int)a * 100;
	bb = (int)(b-a) * 100;

	for (int i = 0; i < n; i++){
		// losowanie z (a,b)
		Xlos = (rand() % bb) + aa;
		Xlos = Xlos / 100;

		// wartosc
		fx = f(Xlos);
		suma += fx;

		//cout << "xlos = " << Xlos << "  f(xlos) = " << fx << "  Nowa suma = " << suma << endl;
	}

	return stala * suma;
}

/*
float calka(a,b,n){n*losuj xi , licz suma(f(xi))

wczytaj a, b, n
wypisz Calka(a,b,n);
*/