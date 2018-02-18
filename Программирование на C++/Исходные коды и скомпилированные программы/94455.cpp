#include <iostream>
using namespace std;

int main ()
{
	int a = 5, b =7;
	double f = 1.281713;
	
	int c = a + b;
	int p = c + f;
	double d = a + p;
	float t = f + a;
	cout << "c: " << c << "\np: " << p << "\nt: " << t << endl;
	return 0;
}