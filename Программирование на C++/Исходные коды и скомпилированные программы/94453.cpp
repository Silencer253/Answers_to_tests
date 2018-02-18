#include <iostream>
using namespace std;

namespace A
{
	struct X;
	struct Y;
	void f(int);
	void g(X);
}

namespace B
{
	void f(int i);
	void g(A::X);
	void h(A::Y);
	void main;
}

void B::main ()
{
	f(100);
	A::X x;
	g(x);
	A::Y y;
	h(y);
}