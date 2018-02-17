#include <iostream>
using namespace std;

template<typename X> class complex
{
	public:
		complex(){}
		template<class T> complex(const complex<T>& c){cout << "1";}
		complex(const complex<int>& c){cout << "2";}
		template<class T> complex(complex<T*>& c){cout << "3";}
};

int main()
{
	complex<int> c1;
	complex<double> c2;
	complex<int*> c3;
	
	complex<int> c4(c3);
	complex<int> c5(c1);
	complex<int> c6(c2);
	complex<float> c7(c1);
	complex<double> c8(c2);
	
	cin.get();
	return 0;
}