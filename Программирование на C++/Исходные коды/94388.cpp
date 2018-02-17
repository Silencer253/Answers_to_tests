#include <iostream>
#include <string>
using namespace std;

struct Student 
{
	string FirstName;
	string LastName;
	int year;
};

struct Person
{
	char* FirstName;
	char* LastName;
	int age;
};

int main()
{
	Person person;
	person.FirstName = "Ivan";
	person.LastName = "Ivanov";
	person.age = 23;
	//Student student = (Student)person;
	cout << "person: " << person.FirstName << endl;
	//cout << "student: " << student.FirstName << endl;
	
	return 0;
}