#include <iostream>
#include <vector>
using namespace std;

template<class T, template<class U, class = allocator<U> > class Seq>
void printSeq(Seq<T>& seq)
{
	for(typename Seq<T>::iterator b = seq.begin(); b != seq.end(); )
		cout << *b++ << endl;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	printSeq(v);
	return 0;
}