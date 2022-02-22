#include <iostream>

using namespace std;

class ClassName {

	// переменные и функции по работе с классом ClassName - члены класса

	int x; // поле класса

	int getX() {  // метод класса
		return x;
	}


};

// Vector - массив из N целых чисел

class Vector {
private: // закрытая область
	int size; // размер вектора
	int* data; // указатель на данные вектора

public: // открытая область

	// int Vector_getSize_Vector*(Vector* this) {
	//   return this->size;
	// }
	int getSize() {
		return this->size;
	}

	// void Vector_setSize_Vector*_int(Vector* this, int size) {
	//   this->size = size;
	//   this->data = new int[size];
	// }
	void setSize(int size) {
		this->size = size;
		data = new int[size];
	}

private:

};

int main() {
	// один класс и две переменных с типом ClassName
	ClassName obj1; 
	ClassName obj2;

	int size1; // размер первого вектора
	int* data1; // указатель на данные первого вектора

	int size2; // размер второго вектора
	int* data2; // указатель на данные второго вектора

	// int* sumVectors(int* data1, int size1, int* data2, int size2, int& size3);

	Vector v1; // sizeof(v1) = sizeof(v1.size) + sizeof(v1.data) 
	// = sizeof(int) + sizeof(int*) = 8 (32bit)
	v1.setSize(5); // Vector_setSize_Vector*_int(&v1, 5);
	v1.setSize(10); // Vector_setSize_Vector*_int(&v1, 10);

	Vector v2;
	v2.setSize(10); // Vector_setSize_Vector*_int(&v2, 10);


	return 0;
}