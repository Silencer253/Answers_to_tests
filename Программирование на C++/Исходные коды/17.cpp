#include <iostream>
using namespace std;
int main()
{
	try {
		throw 56;
	}
	catch (...){cout << "..." << endl; return 1;}
	catch (long){cout << "long" << endl; return 1;}
	catch (int){cout << "int" << endl; return 1;}
}