#include <iostream>

int& FunctionReturningReference(int &param)
{
    int i = param;
	param = 40;
	return param;
    //function_returning_reference.cpp:5:9: warning: reference to local variable ‘i’ returned [-Wreturn-local-addr]
    //return i;
}

int main()
{
	int var = 10;
	FunctionReturningReference(var) = 200;
	std::cout<<var<<std::endl;
	return 0;
}
