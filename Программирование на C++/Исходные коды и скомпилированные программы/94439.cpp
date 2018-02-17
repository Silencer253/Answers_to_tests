#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> myvector;
	for(int i=1; i<6; i++) myvector.push_back (i*10);
	
	int myints[] = {10,20,80,320,1024};
	pair<vector<int>::iterator,int*> mypair;
	
	mypair = mismatch (myvector.begin(), myvector.end(), myints);
	cout << *mypair.first << " " << *mypair.second << endl;
	
	return 0;
}