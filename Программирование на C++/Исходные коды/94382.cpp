#include <iostream>
using namespace std;

void* operator new(size_t size) throw (std::bad_alloc)
{
	return 0;
}

int main()
{
	int* p = new int;
	*p = 0;
	return 0;
}