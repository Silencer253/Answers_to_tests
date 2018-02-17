class A{
	~A() throw(){}
};

void bar() throw(int, float) {
	throw 4.f;
}

int main()
{
	try{}
	catch(...){throw;}

	try{}
	catch(int,float){}

	try{
		try{}catch(...){}
	}
	catch(...){}
}