#include <iostream>
using namespace std;

#define max(a,b) a < b ? b : a

int main ()
{
	int a = 10;
	int b = 20;
	int m = max(a += 5, b);
	cout << m << endl;
	return 0;
}