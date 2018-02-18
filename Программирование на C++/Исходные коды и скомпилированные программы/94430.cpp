#include <iostream>
using namespace std;
class MemMan
{
	void *pBlock;
	unsigned BlockSize;
public:
	void alloc(unsigned size);
	void free();
	void *getPtr() const;
};

void MemMan::alloc(unsigned size)
{ pBlock = new char[size]; BlockSize = size; }

void MemMan::free()
{ delete pBlock; pBlock = NULL; BlockSize = 0; }

void *MemMan::getPtr() const { return pBlock; }


int main()
{
	MemMan mm;
	mm.alloc(1024);
	mm.free();
	
	char *ptr = (char *)mm.getPtr();
	memcpy(ptr,"class MemMan tested...", 1024);
	printf("%s\n",ptr);
	
	mm. free();
	
	return 0;
}
