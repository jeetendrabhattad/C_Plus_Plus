#include "Student.h"
#include <iostream>

Student::Student(){
		std::cout<<"Default Constructor\n";	
}

Student::Student(int, char [], float, float, float){
	std::cout<<"Parameterized Constructor\n";	
}

void Student::SetStudentDetails(int, char[], float, float, float)
{
	std::cout<<"Set Student Details\n";	
}

int Student::GetRollNo() const{
	return m_iRollNo;
}

const char* Student::GetName() const{
	return m_cName;
}

float Student::GetM1Marks() const{
	return m_fMarks[0];
}

float Student::GetM2Marks() const{
	return m_fMarks[1];
}

float Student::GetM3Marks() const{
	return m_fMarks[2];
}

Student::~Student(){

}

inline std::istream& operator>>(std::istream &is, Student &st)
{
	// accept student details
	// call set method to set the student details
	std::cout<<"Overloaded >>(extraction) method called\n";
	return is;
}

inline std::ostream& operator<<(std::ostream &os, Student &st)
{
	// call get method on st & print the details
	os<<"Overloaded <<(insertion) method called\n";
	return os;
}
main()
{
	Student st1, st2;
	std::cin>>st1>>st2;
	std::cout<<st1<<st2;
	// operator<<(operator<<(cout, st1), st2)
}

