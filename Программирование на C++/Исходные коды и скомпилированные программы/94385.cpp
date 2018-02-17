#include <iostream>
#include <memory>
using namespace std;

void use(auto_ptr<int> ptr)
{
	(*ptr)++;
}

int main()
{
	auto_ptr<int> p(new int(10));
	use(p);
	cout << *p << endl;
	
	return 0;
}