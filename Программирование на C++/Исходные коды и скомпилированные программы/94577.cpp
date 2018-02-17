int *pi = new int[100];
for(int i = 0; i < 100; ++i)
	pi[i] = 0;
for(int* p = pi+50; p < pi+100; ++p)
	*p = *(p+1) - 20;