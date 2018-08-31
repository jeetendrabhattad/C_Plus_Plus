#include <iostream>
class Course
{
	int courseid;
	public:
	friend class Student;
	friend void PrintStudentDetails();
/*	void PrintStudent()
	{
		Student obj;
		obj.rollNo = 100;
	}*/
};
class Student
{
	int rollNo;
	int division;
	public:
	Student()
	{
		Course c1;
		c1.courseid = 19;
	}
	~Student()
	{

	}
	friend void PrintStudentDetails();
	/* void PrintStudentDetails()
	{
		Course c;
		c.courseid = 10;
//		Student s;
//		std::cout<<s.rollNo<<":"<<s.division;
	}*/
};

void PrintStudentDetails()
{
	Course c;
	c.courseid = 10;
	Student s;
	s.rollNo = 1;
	s.division = 12;
	std::cout<<s.rollNo<<":"<<s.division;
}

int main()
{
	PrintStudentDetails();
	return 0;
}
