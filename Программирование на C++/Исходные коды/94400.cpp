#include <iostream>
#include <exception>
using namespace std;
int main() try {
	throw 100;
}
catch (bool){count << "bool" << endl; return 1;}
catch (char*){count << "char*" << endl; return 1;}
catch (std::exception){count << "std::" << endl; return 1;}
