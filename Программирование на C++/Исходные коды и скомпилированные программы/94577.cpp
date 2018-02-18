// Чтобы получить ошибку, необходимо компилировать только с помощью g++
#include <iostream>
using namespace std;

int main ()
{
	for(int j = 0; j < 100000000; ++j){
		int *pi = new int[100];
		for(int i = 0; i < 100; ++i)
			pi[i] = 0;
		for(int* p = pi+50; p < pi+100; ++p)
			*p = *(p+1) - 20;
	}
	
	return 0;
}