#include <iostream>
using namespace std;

class Bird
{
	public:
		void fly(){cout << "FLY!" << endl;}
};

class Plane: Bird
{
	public:
		using Bird::fly;
};

int main()
{
	Plane* superjet100 = new Plane();
	superjet100->fly();
	
	return 0;
}