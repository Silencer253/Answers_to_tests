#include<vector>

class Student
{
public:
	/*...*/
	int age;
};

int main()
{
	/*...*/
	std::vector<Student*> students;
	const std::vector<Student*>& st = students;
	/*...*/
	std::vector<Student*>::const_reverse_iterator i;
	for (i = st.rend(); i != st.rbegin(); ++i)
	{
		(*i)->age = 20;
	}
	
	return 0;
}