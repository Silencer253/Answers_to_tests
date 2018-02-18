#include<iostream>
using namespace std;

int main()
{
	int _1BallCoordX = 10;
	int _1BallCoordY = 10;
	
	double 1BallCoordX2 = _1BallCoordX * _1BallCoordX;
	double 1BallCoordY2 = _1BallCoordY * _1BallCoordY;
	double BallR = sqrt(1BallCoordX2 + 1BallCoordY2);
	cout << BallR << endl;
	
	return 0;
}