namespace X 
{
	int x = 5;
	namespace Y
	{
		int x = 2;
		void f()
		{
			for(int i = 1; i < 10; ++i)
			{
				int y = x;
				::x += X::x * x;
			}
		}
	}
}