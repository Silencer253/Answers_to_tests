


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
	map<int,string> m;
	m.insert(make_pair(13, "One")); 
	auto it = m.find(13);
	if(it != m.end())
	{
		const_cast<int&>(it->first) = 100000;
	}
	cout << it->first() << endl;
	cout << it->second << endl;
	
	cin.get();
	return 0;
}