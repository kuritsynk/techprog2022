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


	return 0;
}