#include <iostream>

using namespace std;

class ClassName {

	// переменные и функции по работе с классом ClassName - члены класса

	int x; // поле класса

	int getX() {  // метод класса
		return x;
	}


};

int main() {
	// один класс и две переменных с типом ClassName
	ClassName obj1; 
	ClassName obj2;

	return 0;
}