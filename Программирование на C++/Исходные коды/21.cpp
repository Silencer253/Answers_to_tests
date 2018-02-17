#include <iostream>
using namespace std;

int f(int arg)
{
	if(arg==1 || arg==0)
		return 1;
	if(arg%2==0)
		return f(arg/2)+2;
	else
		return f(arg-1)+3;
}

int main()
{
	cout << f(7) << endl;
	return 0;
}