#include <iostream>
using namespace std;

struct First
{
	First(){cout << "First()"; }
	virtual ~First(){cout << "~First()";}
};

struct Second: First
{
	Second(){cout << "Second()";}
	~Second(){cout << "~Second()";}
};

int main ()
{
	First* first = new Second();
	delete first;
	return 0;
}