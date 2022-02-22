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
private: // закрыта€ область
	int size; // размер вектора
	int* data; // указатель на данные вектора

public: // открыта€ область

	//  онструктор по умолчанию
	// —писок инициализации: инициализаци€ полей в пор€дке их объ€влени€
	Vector() : data(nullptr), size(0) {
		// здесь пол€ уже проинициализированы
	}

	Vector(int size) : size(0), data(nullptr) {
		setSize(size);
	}

	~Vector() {
		setSize(0);
	}

	// Vector& Vector_operator=_Vector*_Vector&(Vector* this, const Vector& r)
	Vector& operator=(const Vector& r) {
		if (this == &r) {
			// присвоение самому себе
			return *this;
		}

		setSize(r.size);
		for (int i = 0; i < size; ++i) {
			data[i] = r.data[i];
		}

		return *this;
	}

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
	void setSize(int size); 

	void print();

private:

};

void Vector::setSize(int size) {
	if (size < 0) {
		throw new std::exception("Incorrect size");
	}

	if (data != nullptr) {
		delete[] data;
		data = nullptr;
		this->size = 0;
	}

	if (size == 0) {
		return;
	}

	this->size = size;
	data = new int[size];
}

void Vector::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << std::endl;
	}
}

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
	// v2.setSize(-10); // == v2.setSize(10) -- исключение
	v2.setSize(0); // очистка выделенной динамической пам€ти

	v2 = v2;

	Vector* pv = new Vector(); 
	// 1. ¬ыделение пам€ти в куче в размере sizeof(Vector) байт 
	// 2. ¬ызов конструктра (в данном случае   по умолчанию) дл€ Vector: pv->Vector()
	pv->setSize(5);
	pv->print();


	{
		Vector v3(10); // вызываетс€ конструктор v3.Vector(10)
		v3 = v2; // v3.size=v2.size; v3.data=v2.data
		// v3.operator=(v2),  Vector_operator=_Vector*_Vector&(&v3, v2)

		v3.print();
	} // вызываетс€ деструктор v3: v3.~Vector() // delete[] v3.data == delete[] v2.data

	v2.print();

	delete pv; 
	// 1. ¬ызываетс€ деструктор pv->~Vector()
	// 2. ќсвобождаетс€ пам€ть по указателю pv

	return 0;
}