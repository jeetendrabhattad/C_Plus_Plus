#include <iostream>

class Exception
{

};

void foo()
{
	Exception e;
	std::cout<<"In Function Foo throwing exception\n";
	throw e;
}


int main()
{
	try
	{
		foo();
	}
	catch(Exception e)
	{
		std::cout<<"Caught Exception\n";
	}	
}







