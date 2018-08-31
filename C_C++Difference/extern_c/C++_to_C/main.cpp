#include <iostream>
// tells compiler that this function is defined in C object file.
#ifdef __cplusplus
extern "C" {
#endif
int add(int, int);
#ifdef __cplusplus
}
#endif
void DemoCCallFromCPP()
{
	// calling C function from C++.
	std::cout<<"Calling C function to Add, result is "<<add(10, 20)<<std::endl;
}

int main()
{
	DemoCCallFromCPP();
}
