#include <iostream>
using namespace std;

class FunnyTest
{
	char *s[3];
	
	public:
	void CalcResult(int qst,int ans)
	{
		switch (qst){
			case 0: s[qst] = ans ? "kind" : "evil"; break;
			case 1: s[qst] = ans ? "handsome" : "freak"; break;
			case 2: s[qst] = ans ? "clever" : "stupid"; break;
			default: s[qst] = "";
		}
	}
	
	void PrintResult()
	{
		char *s = "No offence meant, it's joke only";
		printf("********* FUNNY TEST RESULT: *********\n");
		printf("You are %s %s and %s.\n", this->s[0], this->s[1], this->s[2]);
		printf("********* END OF MESSAGE *********\n");
		printf("%s\n", s);	
	}
};
int main ()
{
	FunnyTest ft;
	ft.CalcResult(0,0); ft.CalcResult(1,0); ft.CalcResult(2,0);
	ft.PrintResult();
}