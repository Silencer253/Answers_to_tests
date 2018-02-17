#include<iostream>
using namespace std;

template<class T>
class X
{
	typename T::id i;
public:
	void f(){i.g();}
};

class Y
{
public:
	class id{
		public:
		void g(){}
	};
};

int main()
{}