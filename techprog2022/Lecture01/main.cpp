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

	return 0;
}