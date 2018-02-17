#include <iostream>
using namespace std;

template<typename T>
const T& min_(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

int main()
{
	min_(5,6.);
	min_((char*)"abc", (char*)"ghj");
	min_('c', 'f');
	min_(false,true);
	min_(new int(5), new int(7));
	
	return 0;
}