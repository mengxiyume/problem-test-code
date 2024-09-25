#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A" << endl; }
};
class B {
public:
	B() { cout << "B" << endl; }
};
class C {
public:
	C() { cout << "C" << endl; }
};
class D {
public:
	D() { cout << "D" << endl; }
};
C c;
int main() {
	A a;
	B b;
	static D d;
	return 0;
}