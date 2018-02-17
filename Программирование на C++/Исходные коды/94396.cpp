#include <iostream>
#include <string>
using namespace std;

class Man{
	string name_;
public:
	Man():name_("Unknown"){}
	Man(string name): name_(name){}
	~Man(){cout << name_ << " gone" << endl;}
};

int main()
{
	try{
		static Man man1("Bill");
		Man mans[2];
		throw 5;
		Man man4 = string("Carl");
	}
	catch(...){	
	}
	cin.get();
	return 0;
}