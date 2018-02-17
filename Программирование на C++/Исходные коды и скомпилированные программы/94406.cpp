#include <iostream>
using namespace std;



class Foo
{
public:
	Foo(int i): int_(i){}
	Foo(Foo& f):int_(f.int_){}
private:
	int int_;
};

int main()
{
	Foo foo1(111);
	Foo foo2(foo1);
	return 0;
}