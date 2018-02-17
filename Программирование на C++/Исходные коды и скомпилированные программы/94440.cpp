#include <iostream>
using namespace std;

class A
{
	public:
	void f() {cout << "1";}
	void f(int) {cout << "2";}
};

class B: public A
{
	public:
		using A::f;
		void f(bool){cout << "3";}
};

int main()
{
	B b;
	b.f(true);
	b.f(2);
	b.f();
	return 0;
}
