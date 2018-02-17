class B;
class A
{
	friend class B;
	A(){}
};

class B: virtual public A
{
public:
	B(){}
};

class C : public B
{
public:
	C(){}
};

int main()
{
	C cl_;
	return 0;
}