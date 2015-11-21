#include <iostream>

using namespace std;

class Playground; // dummy!


class Ball{
	int x, y;
public:
	Ball();
	Ball(int x0, int y0) : x(x0), y(y0){}
	void Kopnij(int dx, int dy);
	void Pokaz();
	friend bool Referee(const Playground&, const Ball&);
};


class Playground{
	int x, y, bok;
public:
	Playground();
	Playground(int x0, int y0, int bok) : x(x0), y(y0), bok(bok){}
	friend bool Referee(const Playground&, const Ball&);
};


bool Referee(const Playground&, const Ball&);
void Play();


int main(){
	Play();
	system("PAUSE");
	return 0;
}

/*
	Ball
*/
Ball::Ball(){
	this->x = 20;
	this->y = 20;
}

void Ball::Kopnij(int dx, int dy){
	this->x += dx;
	this->y += dy;
}

void Ball::Pokaz(){
	cout << "Pilka w ( " << this->x << " , " << this->y << " )" << endl;
}

/*
	Playground
*/
Playground::Playground(){
	this->x = 10;
	this->y = 10;
	this->bok = 100;
}

/*
	Referee
*/
bool Referee(const Playground& playground, const Ball& ball){
	return
		(ball.x >= playground.x) && 
		(ball.x <= playground.x + playground.bok) && 
		(ball.y >= playground.y) && 
		(ball.y <= playground.y + playground.bok)
	;
}

/*
	Play!
*/
void Play(){

	cout << " P I L K A \n\n\n";

	int bx, by, bb;
	cout << "Podaj wymiary boiska: x, y, bok" << endl;
	cin >> bx >> by >> bb;

	Playground boisko(bx,by,bb);

	Ball pilka;

	int dX, dY;

	while (Referee(boisko, pilka)){
		
		cout << "Pilka w polu!" << endl;
		cout << "Kopnij, x = ";
		cin >> dX;
		cout << "Kopnij, y = ";
		cin >> dY;

		pilka.Kopnij(dX, dY);
		pilka.Pokaz();
	}

	cout << "Pilka na aucie!" << endl;
	cout << "GAME OVER" << endl;
}

// klasa przyjazna udostepnia swoje pola prywatne.
/*
jesli w klasie K1 zdeklarujemy friend class K2, 
to znaczy ze K1 uznaje K2 za przyjaiela i udostepnia mu swoje pola prywatne
*/