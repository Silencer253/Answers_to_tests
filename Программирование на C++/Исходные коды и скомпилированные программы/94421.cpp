#include <iostream>
using namespace std;

class Zero{};

class One: public Zero{};
class Two: public Zero{};

int main()
{
	One* pO = new One;
	Two* pT = new Two;
	
	cout << (typeid(pO) == typeid(pT)) << endl;
	cin.get();
	return 0;
}
