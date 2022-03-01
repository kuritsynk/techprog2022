#include <iostream>

using namespace std;

class A {
	int a;

public:
	A(int a) : a(a) {}

	// int A_getA_A*(A* this)
	int getA() const {
		return a;
	}

	// void A_print_A*(A* this)
	void print() const {
		cout << "a=" << a << endl;
	}
};

// композиция классов
class B {
	A a;
	int b;

public:

	B(int a, int b) : a(a), b(b) {}

	int getA() {
		return a.getA();
	}

	const A& getAObj() const {
		return a;
	}

	int getB() const {
		return b;
	}

	void print() const {
		a.print();
		cout << "b=" << b << endl;
	}

};

// наследование
class C : public A {
	int c;

public:
	C(int a, int c) : c(c), A(a) {}

	// int C_getC_C*(C* this)
	int getC() const {
		return c;
	}

	// void C_print_C*(C* this)
	void print() {
		// A_print_A*((A*) this)
		A::print();
		cout << "c=" << c << endl;
	}
};


// foo_A(A x)
void foo(A x) {
	// if (A_getA_A*(&x) > 0) {
	if (x.getA() > 0) {
		// A_print_A*(&x) - адрес функции зафиксирован на этапе компиляции
		x.print();
	}
}

int main() {
	A a(2);
	a.print(); // a=2
	foo(a); // a=2

	B b(3, 4);
	b.print(); // a=3 b=4
	b.getAObj().print(); // a=3

	// foo(b) - b - не является объектом типа A
	foo(b.getAObj());

	const A* pa = &b.getAObj();
	pa->print(); // a=3

	C c(3, 4); // первые sizeof(A) байт - это класс A
	// C_print_C*(&c)
	c.print(); // a=3 c=4

	// A_getA_A*((A*)&c)
	int ca = c.getA(); // ca=3
	foo(c); // полиморфизм: объекты класса-наследника
	// можно использовать в функциях, работающих с базовым классом
	
	// выводится: a=3 (c = 4 не пишется)
	// полиморфизм - статический
	

	return 0;
}