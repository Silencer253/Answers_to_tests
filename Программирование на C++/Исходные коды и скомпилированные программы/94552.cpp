int main()
{
	char a,b;
	const char *pcc = &a;

	pcc = &b;
	*pcc = 'Z';
}