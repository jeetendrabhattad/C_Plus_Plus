#include "stack_template.h"


int main()
{
	Stack<int> intStack;
	Stack<double> doubleStack;
	std::cout<<"Class Template Example\n";
	intStack.push(10);
	std::cout<<"Value at Top:-"<<intStack.peep()<<std::endl;
	doubleStack.push(10.20136545454);
	std::cout.precision(10);
	std::cout<<"Value at Top:-"<<doubleStack.peep()<<std::endl;
	std::cout<<"poping from stack:-"<<intStack.pop()<<std::endl;
	std::cout<<"poping from stack:-"<<intStack.pop()<<std::endl;	
}
