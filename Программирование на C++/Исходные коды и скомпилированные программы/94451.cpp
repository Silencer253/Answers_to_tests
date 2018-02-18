#include <iostream>
using namespace std;

template<typename T>
T min(T a, T b){
	cout << "T"; return (a < b) ? a : b;
}

template<> int Min(int a, int b){
	cout << "i"; return (a < b) ? a : b;
}

double Min(double x, double y){
	cout << "d"; return (x < y) ? x : y;
}

int main ()
{
	Min(1,2);
	Min(7.8, 10);
	Min(true, false);
	Min("abc", "bcd");
	Min(false, 'c');
	
	return 0;
}