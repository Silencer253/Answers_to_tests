
#include <string>
using namespace std;


class CStudent{};

class CStudentList
{
	/*...*/
	static int count;
	static const int MAX_STUDENT_NUM = 50; //1
	CStudent students[5]; //2
	
public:
	CStudentList(){}
	void AddStudent(string name = "", string surname = "", int age){} //3
	static int GetMaxNumStudent();
	
};

CStudentList::GetMaxNumStudent() {return MAX_STUDENT_NUM;} //4

int CStudentList::count; //5
