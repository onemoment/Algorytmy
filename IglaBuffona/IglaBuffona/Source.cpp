#include <iostream>
#include <time.h>

using namespace std;

class IglaBuffona{

	double y;
	double alfa;
	int licznik;
	double l;
	double d;
	int ilosc;
	int rozmiar_podlogi;

	void losuj();
public:
	IglaBuffona(double dlugosc_igly, double odleglosc_miedzy_liniami);
	void losowania(int ilosc_losowan);
	void wyniki();
};



int main(){

	srand(time(0));

	double ll;
	double dd;
	int nn;

	cout << "Podaj dlogosc igly, l = ";
	cin >> ll;

	cout << "Podaj odleglosc miedzy liniami, d = ";
	cin >> dd;

	cout << "Podaj ilosc rzutow, n = ";
	cin >> nn;

	IglaBuffona igla = IglaBuffona(ll, dd);
	igla.losowania(nn);

	system("PAUSE");
	return 0;
}



IglaBuffona::IglaBuffona(double dlugosc_igly, double odleglosc_miedzy_liniami){
	this->l = dlugosc_igly;
	this->d = odleglosc_miedzy_liniami;
	this->rozmiar_podlogi = 100;
}

void IglaBuffona::losuj(){

	double y1 = 0;
	double kreska;

	for (int i = 0; i < this->ilosc; i++){
		
		// losowania
		this->y = ((double)rand() / (double) RAND_MAX) * 100; // (0,100)
		this->alfa = ((double)rand() / (double) RAND_MAX) * 3.14159265358; // (0,2PI)

		// obliczenia
		y1 = this->y + this->l * sin(this->alfa);

		// out
		if (this->ilosc < 20){
			cout << "y = " << this->y << "   y1 = " << y1 << "   alfa = " << this->alfa << endl;
		}

		// sprawdzanie
		kreska = 0;
		while ( kreska <= this->rozmiar_podlogi){

			if (kreska >= this->y && kreska <= y1){
				this->licznik++;
				break;
			}

			kreska += this->d;
		}	
		//
	}
}

void IglaBuffona::losowania(int ilosc_losowan){
	this->ilosc = ilosc_losowan;
	this->licznik = 0;
	losuj();
	wyniki();
}

void IglaBuffona::wyniki(){
	if (this->licznik != 0){
		double pi_ = (2 * this->l * this->ilosc) / (this->d * this->licznik);
		cout << "Po wykonaniu " << this->ilosc << " rzutow, pi = " << pi_ << endl;
	}
	else{
		cout << "Igla nigdy nie przeciela linii.." << endl;
	}
}

/*
losujemy y i k¹t, wyliczamy polozenie i sprawdzamy czy igla przeciela. jak tak to p++
l - dlogosc igly <=d - odleglosc miedzy liniami

 


*/