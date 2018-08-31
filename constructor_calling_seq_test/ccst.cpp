#include <iostream>
#include <stdlib.h>
using namespace std;

class ConstructorCallingSequenceTest
{
	int j;
	public:
		ConstructorCallingSequenceTest(int i) : j(i)
		{
			cout<<"Constructor Called"<<i<<"\n";
		}
		~ConstructorCallingSequenceTest()
		{
			cout<<"Destructor Called"<<j<<"\n";
		}
}t1(1), t2(2);

ConstructorCallingSequenceTest t3(3), t4(4);


int foo()
{
	ConstructorCallingSequenceTest t10(10), t11(11);
	exit(0);
}
int main()
{
	ConstructorCallingSequenceTest t5(5), t6(6);
	{
		ConstructorCallingSequenceTest t7(7), t8(8);	
	}
	foo();
}

	// exit results into returning control directly to the __start i.e the one who has called main.
	// Due to this destructors of current function & any previous functions (which are present on stack) will not be invoked.
	// Destructors of global objects will be invoked.
	//return 1;
