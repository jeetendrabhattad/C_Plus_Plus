#include <stdio.h>

void CallCPPFunctionFromCDemo()
{
	// calling add function defined in C++
	printf("Result of Addition is %d\n", _Z3addii(10, 20));
}

int main()
{
	CallCPPFunctionFromCDemo();
}
