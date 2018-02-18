#include <iostream>
using namespace std;

class A{
public: ~A(){cout << "A";}
};

class B{
public: ~B(){cout << "B";}
};

int main ()
{
	try{
		A a;
		B b[3];
		throw 5;
	}
	catch(...){
	}
	return 0;
}