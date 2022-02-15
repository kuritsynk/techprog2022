#include <iostream>

// Пространство имен

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

// int min_int_int - внутреннее название функции
int min(int a, int b) {
	return a < b ? a : b;
}

// min_double_double - внутреннее название функции
double min(double a, double b) {
	return a < b ? a : b;
}

void print(int x) {
	cout << "x=" << x << endl;
}

void print(int x, bool negativeInBrackets) {
	if (x < 0 && negativeInBrackets) {
		cout << "x=(" << -x << ")" << endl;
	}
	else {
		cout << "x=" << x << endl;
	}
}

using namespace MySpace::InnerSpace;
using namespace std;

int main() {
	std::cout << "Hello" << std::endl;

	std::cout << "k=" << k << std::endl;
	std::cout << "k in myspace = " << MySpace::k << std::endl;

	std::cout << "global foo() returns " << foo() << std::endl;
	std::cout << "myspace foo() returns " << MySpace::foo() << std::endl;

	std::cout << "superFoo() returns " << superFoo() << std::endl;

	cout << "using cout without specifing std" << endl;

	// Перегрузка функций

	int z = min(3, 6); // z = min_int_int(3, 6)
	cout << "z=min(3, 6)=" << z << endl; // 3
	cout << "min(3.14, 2.78)=" << min(3.14, 2.78) << endl; 
	  // 2.78 = min_double_double(3.14, 2.78)

	min(3.14, 2.78); // min_double_double(3.14, 2.78)

	print(2); // x=2
	print(-2, true); // x=(2)


	return 0;
}