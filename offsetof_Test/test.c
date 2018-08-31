#include <stdio.h>
#include <stddef.h>
typedef struct 
{
	int i;
	char c;
	int j;
	char data;
}Student;

typedef struct
{
	char c;
	double d;
	int j;
}temp;
int main()
{
	Student t1;
	printf("\n offset of i = %d, c = %d, j = %d, data = %d\n", offsetof(Student, i), offsetof(Student, c), offsetof(Student, j), offsetof(Student, data));
	printf("\n offset of c = %d offset of d = %d j = %d\n", offsetof(temp, c), offsetof(temp, d), offsetof(temp, j));
}
