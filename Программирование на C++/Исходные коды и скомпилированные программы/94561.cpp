#include <iostream>
using namespace std;

template<class T = int, int N=100> //1
class Stack{
	T data[N];
	size_t count;
public:
	void push(const T& t){}
	/**/
};

int main()
{
	Stack<> myStack; //2
	Stack<float, 5> flStack1;
	Stack<float, 6> flStack2;
	Stack<int, 100> intStack;
	intStack = myStack; //3
	flStack1 = flStack2; //4
	return 0;
}
