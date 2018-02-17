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
	std::vector<Student*>& st = students;
	const std::vector
	/*...*/
	std::vector<Student*>::const_reverse_iterator i;
	for (int i = st.rend(); i != st.rbegin(); ++i)
	{
		(*i)->age = 20;
	}
	
	return 0;
}