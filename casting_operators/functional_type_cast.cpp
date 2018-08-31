#include <iostream>

int main()
{
	int a = 20;
	float f = 3.5f;
	a = (int)f; // c-style type-casting
	a = int(f); // C++ style type-casting.	
			// functional style type-casting.
	a = static_cast<int>(f); // same as above
	
	const int i = 10;
	//i = 20;
	int *ptr = const_cast<int*>(&i); // removing the constant-ness of i.
//	int *ptr = &i;

	*ptr = 20;
	std::cout<< ptr <<":"<< &i<<std::endl;
	std::cout<<"value of ptr "<<*ptr<<": i"<<i<<std::endl;
	int b = *ptr + i;
	std::cout<<"value of b is "<<b<<std::endl;
//	const int * const cptr = &i;
//	*cptr = 20;
}
