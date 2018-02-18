#include <iostream>
using namespace std;

class A {
public:
	A(){ cout << "+A";}
	~A(){ cout << "-A";}
};

int main()
{
	delete new A[1];
	return 0;
}
