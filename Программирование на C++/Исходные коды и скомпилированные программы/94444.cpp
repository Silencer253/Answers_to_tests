#include <iostream>
using namespace std;

int main()
{
	double x,y;
	cin >> x >> y;
	
	try{
		double A_1 = 2*x*y /(x+y);
		cout << A_1 << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
	return 0;
}
