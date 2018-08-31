#ifndef STUDENT_H
#define STUDENT_H

class Student{
	int m_iRollNo;
	char m_cName[20];
	float m_fMarks[3];
	public:
	Student();
	Student(int, char [], float, float, float);
	void SetStudentDetails(int, char[], float, float, float);
	int GetRollNo() const;
	const char* GetName() const;
	float GetM1Marks() const;
	float GetM2Marks() const;
	float GetM3Marks() const;
	~Student();
};
#endif
