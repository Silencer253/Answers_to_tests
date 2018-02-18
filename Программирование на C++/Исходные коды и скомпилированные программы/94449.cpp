#include <iostream>
using namespace std;

class BasicMuxer{/*skipped*/};
class ExtendedMuxer: public BasicMuxer{
	char* m_buffer;
	/*code skipped*/
public:
	ExtendedMuxer(int size);
	/*code skipped*/
	void Finalize() throw (std::exception);
	virtual ~ExtendedMuxer();
};

ExtendedMuxer::ExtendedMuxer(int size){
	if(size < 1024)
		m_buffer = new char[size];
	else
		m_buffer = 0;
	/*code skipped*/
}
/*code skipped*/

void ExtendedMuxer::Finalize() throw (std::exception) {
	if(!m_buffer) throw (new std::exception);
	/*code skipped*/
}

ExtendedMuxer::~ExtendedMuxer(){
	try{
		Finalize();
	}
	catch(...) {
		delete[] m_buffer;
		throw;
	}
	delete[] m_buffer;
	/*code skipped*/
}

int main ()
{

	return 0;
}