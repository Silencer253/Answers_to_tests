#include <iostream>
using namespace std;

struct Base{
	virtual ostream& print(ostream& os) const{
		return os << "Base" << endl;
	}
};

struct Derived: public Base{
	ostream& print(ostream& os) const{
		return os << "Derived" << endl;
	}
};

ostream& operator<<(ostream& os, const Base& base)
{
	return base.print(os);
}
int main(){
	Base b; Derived d;
	cout << b << d;
	return 0;
}
