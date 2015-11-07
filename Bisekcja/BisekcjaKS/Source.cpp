#include<iostream>

using namespace std;

float F0(float x);
float F1(float x);
float F(float x);

bool Bisekcja(float start, float end, float eps, float *wynik);

int main(){

	float a, b;
	float dok;
	float wynik;

	cout << "Podaj dolny kraniec przedzialu, a = ";
	cin >> a;

	cout << "Podaj gorny kraniec przedzialu, b = ";
	cin >> b;

	cout << "Podaj dokladnosc obliczen, eps = ";
	cin >> dok;

	//dok = 0.0002;

	if (Bisekcja(a, b, dok, &wynik)){
		cout << "Miejsce zerowe x0 = " << wynik;
	}

	cout << endl;
	system("PAUSE");
}

float F0(float x){
	return x*x - 9;
}

float F1(float x){
	return x*x + 2 * x - 7;
}

float F(float x){
	return F0(x);
}

bool Bisekcja(float start, float end, float eps, float *wynik){
	float fa, fb, fs;
	float srodek;
	bool poprawnie = false;

	if (end > start){

		if (end - start < eps){
			*wynik = (start + end) / 2.0;
			return true;
		}
		else {
			fa = F(start);
			fb = F(end);

			srodek = (start + end) / 2.0;
			fs = F(srodek);

			if (fa*fs < 0){
				return Bisekcja(start, srodek, eps, wynik);
			}
			else if(fs*fb < 0){
				return Bisekcja(srodek, end, eps, wynik);
			}
			else if( (fs*fa == 0) || (fs*fb ==0)){
				*wynik = srodek;
				return true;
			}
			else{
				cout << "Brak miejsca zerowego.";
				return false;
			}
		}
		//
	}
	else {
		cout << "Niepoprawny przedzial.";
		return false;
	}
}