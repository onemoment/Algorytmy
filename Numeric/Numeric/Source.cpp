#include <iostream>

using namespace std;

double f(double x);
double f1(double x, double h);
double f2(double x, double h);

int main(){

	cout << "Obliczanie pochodnych" << endl;

	double x0;
	double dh;

	cout << "Podaj h = ";
	cin >> dh;

	cout << "podaj punkt, w ktorym liczymy pochodna, x = ";
	cin >> x0;

	cout << "Wartosc funkcji w punkcie f( " << x0 << " ) = " << f(x0) << endl;
	cout << "Wartosc pochodnej f'( " << x0 << " ) = " << f1(x0, dh) << endl;
	cout << "Wartosc drugiej pochodnej f''( " << x0 << " ) = " << f2(x0, dh) << endl;

	system("PAUSE");
	return 0;
}

double f(double x){
	return x*x - 5 * x + 3;
}

double f1(double x, double h){
	return (f(x + h) - f(x - h)) / (2 * h);
}

double f2(double x, double h){
	double h2 = h*h;
	double ff = f(x + h) + f(x - h) - 2 * f(x);

	return ff / h2;
}




/*

wczytaj h
wczytaj x
wyswietl f' (x,h)
wyswietl f'' (x,h)

trzy funkcje f, f1, f2 i wyniki

h = 0,01
zmniejszaæ h i obserwowac wyniki

*/