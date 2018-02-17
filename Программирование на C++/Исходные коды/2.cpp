#include <iostream>
using namespace std;

class A{
	public:
		A(){}
		A(const A&) {cout << "copy";}
};

int main()
{
	try {
		A a1;
		A a2 = a1;
		A a3(a2);
		throw a3;
	}
	catch(A e) {
		
	}
	
	return 0;
}