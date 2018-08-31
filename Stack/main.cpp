#include "stack.h"

void SimulateStack()
{
	Stack st;	
	Stack st1(20);	
	std::cout<<"Is Stack st Empty :- "<<st.isEmpty()<<std::endl;
	std::cout<<"Is Stack st1 Empty :- "<<st1.isEmpty()<<std::endl;
	st.push(20);
	std::cout<<"Is Stack st Empty :- "<<st.isEmpty()<<std::endl;
}

int main()
{
	SimulateStack();
}
