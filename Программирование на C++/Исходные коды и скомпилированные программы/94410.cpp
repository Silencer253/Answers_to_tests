#include<iostream>
using namespace std;

namespace X
{
	
	int x = 5;
	namespace Y
	{
		int x = 2;
		int f()
		{
			for (int i = 1; i < 10; ++i)
			{
				int x = 10;
				X::x += Y::x * x;
			}
			return X::x;
		}
	}
}

int main()
{
	cout << X::Y::f() << endl;
	
	return 0;
}