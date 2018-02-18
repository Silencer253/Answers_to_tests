#include <iostream>
using namespace std;
int main ()
{
	try {
		throw 8.;
	}
	catch (int){cout << "int" << endl; return 1;}
	catch (float){cout << "float" << endl; return 1;}
	catch (double){cout << "double" << endl; return 1;}
}