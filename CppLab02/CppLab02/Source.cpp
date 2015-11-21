#include <iostream>

using namespace std;

class Rectangle{
	int width, height;
public:
	Rectangle(){}
	Rectangle(int x, int y) : width(x), height(y) {}
	int area();
	friend Rectangle duplicate(const Rectangle&);
};

int Rectangle::area(){
	return width * height;
}

Rectangle duplicate(const Rectangle& param){
	Rectangle res;
	res.width = param.width * 2;
	res.height = param.height * 2;
	return res;
}

int funkcja1(int arg){
	arg = arg + 1;
	return arg;
}

int funkcja2(const int &arg){ // const powoduje ze wskaznik jest niemodyfikowalny
	//arg = arg + 1;
	return arg;
}

int main(){

	/* //wskazniki
	int a = 5;
	int *z;
	z = &a;
	
	cout << funkcja1(a) << endl;
	cout << a << endl;

	cout << funkcja2(*z) << endl;
	cout << a << endl;
	*/


	cout << endl;
	system("PAUSE");
	return  0;
}

/*
  piszemy gre komputerowa. 
  funkcja zaprzyjazniona do sprawdzania polozenia pilki
*/