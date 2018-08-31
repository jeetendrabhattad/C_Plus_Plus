#include "stack_template.h"

Stack<int> intStack;
Stack<float> floatStack;

int main()
{
	std::cout<<"Class Template Example\n";
	intStack.push(10);
	std::cout<<"Value at Top:-"<<intStack.peep()<<std::endl;
	floatStack.push(10.20);
	std::cout<<"Value at Top:-"<<floatStack.peep()<<std::endl;
	std::cout<<"poping from stack:-"<<intStack.pop()<<std::endl;
	std::cout<<"poping from stack:-"<<intStack.pop()<<std::endl;	
}
