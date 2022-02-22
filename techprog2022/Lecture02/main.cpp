#include <iostream>

using namespace std;

class ClassName {

	// ���������� � ������� �� ������ � ������� ClassName - ����� ������

	int x; // ���� ������

	int getX() {  // ����� ������
		return x;
	}


};

// Vector - ������ �� N ����� �����

class Vector {
private: // �������� �������
	int size; // ������ �������
	int* data; // ��������� �� ������ �������

public: // �������� �������

	// ����������� �� ���������
	// ������ �������������: ������������� ����� � ������� �� ����������
	Vector() : data(nullptr), size(0) {
		// ����� ���� ��� �������������������
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
			// ���������� ������ ����
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
	// ���� ����� � ��� ���������� � ����� ClassName
	ClassName obj1; 
	ClassName obj2;

	int size1; // ������ ������� �������
	int* data1; // ��������� �� ������ ������� �������

	int size2; // ������ ������� �������
	int* data2; // ��������� �� ������ ������� �������

	// int* sumVectors(int* data1, int size1, int* data2, int size2, int& size3);

	Vector v1; // sizeof(v1) = sizeof(v1.size) + sizeof(v1.data) 
	// = sizeof(int) + sizeof(int*) = 8 (32bit)
	v1.setSize(5); // Vector_setSize_Vector*_int(&v1, 5);
	v1.setSize(10); // Vector_setSize_Vector*_int(&v1, 10);

	
	Vector v2;
	v2.setSize(10); // Vector_setSize_Vector*_int(&v2, 10);
	// v2.setSize(-10); // == v2.setSize(10) -- ����������
	v2.setSize(0); // ������� ���������� ������������ ������

	v2 = v2;

	Vector* pv = new Vector(); 
	// 1. ��������� ������ � ���� � ������� sizeof(Vector) ���� 
	// 2. ����� ����������� (� ������ ������ � �� ���������) ��� Vector: pv->Vector()
	pv->setSize(5);
	pv->print();


	{
		Vector v3(10); // ���������� ����������� v3.Vector(10)
		v3 = v2; // v3.size=v2.size; v3.data=v2.data
		// v3.operator=(v2),  Vector_operator=_Vector*_Vector&(&v3, v2)

		v3.print();
	} // ���������� ���������� v3: v3.~Vector() // delete[] v3.data == delete[] v2.data

	v2.print();

	delete pv; 
	// 1. ���������� ���������� pv->~Vector()
	// 2. ������������� ������ �� ��������� pv

	return 0;
}