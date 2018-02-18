#include <iostream>
using namespace std;
const int N = 10;
double Fibo[N] = {1,1};
double *pElem = &Fibo[2];

//const int Offs1 = sizeof(double);
const int Offs1 = 1;
const int Offs2 = Offs1*2;

int main()
{
	for(int i=2; i<N; i++)
	{
		*pElem = *(pElem - Offs1) + *(pElem - Offs2);
		pElem++;
	}
	
	for(int i=0; i<N; i++)
		cout << Fibo[i] << endl;
	
	return 0;
}