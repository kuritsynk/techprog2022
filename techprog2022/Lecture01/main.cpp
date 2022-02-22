#include <iostream>

// ������������ ����

int k = 5;

int foo() {
	return k;
}

namespace MySpace {

	int k = 6;

	int foo() {
		return k + ::k;
	}

	namespace InnerSpace {

		int superFoo() {
			return foo() + ::foo();
		}
	}

}

using namespace MySpace::InnerSpace;
using namespace std;

// int min_int_int - ���������� �������� �������
int min(int a, int b) {
	return a < b ? a : b;
}

// min_double_double - ���������� �������� �������
double min(double a, double b) {
	return a < b ? a : b;
}

// print_int_bool
void print(int x = 0, bool negativeInBrackets = false) {
	if (x < 0 && negativeInBrackets) {
		cout << "x=(" << -x << ")" << endl;
	}
	else {
		cout << "x=" << x << endl;
	}
}

int foo(int x) {
	// int x - ������� �������� - ��������� ���������� ������� 
	x = x + 1;
	return x;
} // x ������������, �.�. ����� ����� �����������

int fooPtr(int* x) {
	// int* x - ��������� ����������
	cout << "x=" << x << endl;
	*x = *x + 1;  
	return *x;
} 

int& fooRef(int& x) {
	// int& x - ��������� ���������� - ��������� ��� ��������� ����� ���������
	cout << "&x=" << &x << endl;
	x = x + 1;
	return x;
}

int main() {
	std::cout << "Hello" << std::endl;

	std::cout << "k=" << k << std::endl;
	std::cout << "k in myspace = " << MySpace::k << std::endl;

	std::cout << "global foo() returns " << foo() << std::endl;
	std::cout << "myspace foo() returns " << MySpace::foo() << std::endl;

	std::cout << "superFoo() returns " << superFoo() << std::endl;

	cout << "using cout without specifing std" << endl;

	// ���������� �������

	int z = min(3, 6); // z = min_int_int(3, 6)
	cout << "z=min(3, 6)=" << z << endl; // 3
	cout << "min(3.14, 2.78)=" << min(3.14, 2.78) << endl; 
	  // 2.78 = min_double_double(3.14, 2.78)

	min(3.14, 2.78); // min_double_double(3.14, 2.78)

	// print_int_bool(2, false)
	print(2); // x=2
	bool negativeInBrackets = true;

	// print_int_bool(-2, negativeInBrackets)
	print(-2, negativeInBrackets); // x=(2)

	print(); // print_int_bool(0, false)  x=0

	// �������� ���������� � �������

	int k = 2;
	// �������� �� ��������
	int l = foo(k); // l = 3 k = 2 - k �� ���������, foo::x - ����� k
	// int l = tmp (=return foo::x)

	cout << "&k=" << &k << endl;
	l = fooPtr(&k); // l = 3; k = 3; l = tmp (= return fooPtr::x) - ����� &k

	l = fooRef(k); // l = 4; k = 4; l = k // fooRef::x - ��������� ��� k

	{
		int t = 5;
		cout << "&t=" << &t << endl;
	}
	// cout << t << endl; // t - �� ����������
	int s = 5;
	cout << "&s=" << &s << endl;

	int t = 5;
	cout << "&t=" << &t << endl;

	int z1 = ++k; // int& operator++(int& k) { k = k + 1; return k; }
	int y = k++; // int operator++(int&k, int ignored) 
	// { int t = k; k = k + 1; return t;  }


	return 0;
}