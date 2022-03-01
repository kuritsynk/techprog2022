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

	// Конструктор по умолчанию
	// Список инициализации: инициализация полей в порядке их объявления
	Vector() : data(nullptr), size(0) {
		// здесь поля уже проинициализированы
	}

	Vector(int size) : size(0), data(nullptr) {
		setSize(size);
	}

	Vector(const Vector& src);

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

	// Оператор умножения на число справа
	// Vector v1(4), v2 = v1 * 5; // v2 = v1.operator*(5)
	Vector operator*(int r) const {
		Vector result(size);
		for (int i = 0; i < size; ++i) {
			result.data[i] = data[i] * r;
		}
		return result;
	}

	Vector& operator*=(int r) {
		for (int i = 0; i < size; ++i) {
			data[i] *= r; // int& <- int
		}
		return *this;
	}

	// Префиксная форма инкремента: ++a
	Vector& operator++() {
		for (int i = 0; i < size; ++i) {
			++data[i];
		}
		return *this;
	}



	// Постфиксная форма инкремента: a++
	Vector operator++(int ignored) {
		Vector result(*this);
		++(*this);
		return result;
	}

	// int Vector_getSize_Vector*(Vector* this) {
	//   return this->size;
	// }
	int getSize() const {
		return this->size;
	}

	// void Vector_setSize_Vector*_int(Vector* this, int size) {
	//   this->size = size;
	//   this->data = new int[size];
	// }
	void setSize(int size); 

	int& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::exception("Некорректный индекс");
		}
		return data[index];
	}

	void print();

	friend Vector operator+(const Vector& l, const Vector& r);
	friend int operator*(const Vector& l, const Vector& r);
	friend bool operator==(const Vector& l, const Vector& r);

private:

};

Vector::Vector(const Vector& src) : size(0), data(nullptr) {
	setSize(src.size);
	for (int i = 0; i < size; ++i) {
		data[i] = src.data[i];
	}
}

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

// Оператор умножения на число слева - функция
Vector operator*(int l, const Vector& r) {
	return r * l; // r.operator*(l)
}

// Оператор сложения двух векторов - функция
Vector operator+(const Vector& l, const Vector& r) {
	if (l.getSize() != r.getSize()) {
		throw new std::exception("Несовместимые размеры векторов");
	}
	Vector result(l.getSize());
	for (int i = 0; i < l.getSize(); ++i) {
		result.data[i] = l.data[i] + r.data[i];
	}
	return result;
}

// Скалярное произведение двух векторов - функция
int operator*(const Vector& l, const Vector& r) {
	if (l.size != r.size) {
		throw new std::exception("Несовместимые размеры векторов");
	}
	int result = 0;
	for (int i = 0; i < l.size; ++i) {
		result += l.data[i] * r.data[i];
	}
	return result;
}

// Сравнение двух векторов
bool operator==(const Vector& l, const Vector& r) {
	if (l.size != r.size) {
		return false;
	}
	for (int i = 0; i < l.size; ++i) {
		if (l.data[i] != r.data[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const Vector& l, const Vector& r) {
	return !(l == r);
}


void Vector::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << std::endl;
	}
}

void printVector(Vector v) { // локальная переменная v - копией передаваемого объекта
	if (v.getSize() > 5) {
		v.print();
	}
} // уничтожение локальной переменной v: v.~Vector() 

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
	v2.setSize(0); // очистка выделенной динамической памяти

	v2 = v2; // присвоение самому себе должно работать корректно

	Vector* pv = new Vector(); 
	// 1. Выделение памяти в куче в размере sizeof(Vector) байт 
	// 2. Вызов конструктра (в данном случае К по умолчанию) для Vector: pv->Vector()
	pv->setSize(5);
	pv->print();


	{
		Vector v3(10); // вызывается конструктор v3.Vector(10)
		v3 = v2; // v3.size=v2.size; v3.data=v2.data
		// v3.operator=(v2),  Vector_operator=_Vector*_Vector&(&v3, v2)

		v3.print();
	} // вызывается деструктор v3: v3.~Vector() // delete[] v3.data == delete[] v2.data

	v2.print();

	delete pv; 
	// 1. Вызывается деструктор pv->~Vector()
	// 2. Освобождается память по указателю pv

	printVector(v2); // (v.size = v2.size, v.data = v2.data) => KK: v=Vector(v2)
	// после вызова функции могут возникнуть проблемы с v2

	Vector v4 = v2; // КК: v4.Vector(v2)
	v4 = v2;        // = : v4.operator=(v2)

	Vector v5 = v2 * 5; // const Vector tmp = v2.operator*(5); v5 = tmp;

	Vector v6 = 5 * v2;

	v6 = v4 + v2; // v6.operator=(operator+(v4, v2))
	int mult6 = v4 * v2;

	v6 *= 5; // v6 = v6 * 5; -> v6.operator*=(5) - результатом является v6

	++v6; // v6.operator++(); результат - сам v6
	Vector v7 = v6++; // v7.Vector(v6.operator++(0)); результат - новый объект

	std::cout << "v7.data[5]=" << v7[5] << std::endl;

	v7[5] = 7; // v7.operator[](5) = 7; v7.data[5] int& <- int

	return 0;
}