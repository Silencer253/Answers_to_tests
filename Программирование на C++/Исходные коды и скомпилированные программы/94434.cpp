#include <iostream>
using namespace std;

class A{
	int a;
	int g(){return 0;}
};

class B{
	virtual void f(){}
};

int main()
{
	int size = sizeof(A) + sizeof(B);
	cout << size << endl;
	return 0;
}