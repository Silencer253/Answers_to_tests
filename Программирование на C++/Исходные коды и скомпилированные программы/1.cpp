#include <iostream>
using namespace std;

namespace Prog{
	int d = 5;
}

namespace Outer
{
	double d = 100*d;
	namespace Middle
	{
		double d = 10*Prog::d*Outer::d;
		namespace Inner
		{
			int d = Middle::d + Outer::d + d;
		}
	}
}

int main()
{
	using namespace Outer::Middle;
	cout << d;
	
	cin.get();
	return 0;
}