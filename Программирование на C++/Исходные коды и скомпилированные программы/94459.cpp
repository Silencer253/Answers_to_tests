#include <iostream>
#include <exception>
using namespace std;

int main ()
{
	try{
		while(true) {
			int *p = new int[10000];
		}
	}
	catch (std::overflow_error& e)
	{cout << "overflow_error" << endl;}
	catch (std::exception& e)
	{cout << "exception" << endl;}
	catch (std::bad_alloc& e)
	{cout << "bad_alloc" << endl;}
	catch (...)
	{cout << "..." << endl;}
	
	return 0;
}