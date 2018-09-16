#include <iostream>

class Base
{
	int i;
	public:
 	Base(int k) : i(k)
	{
		std::cout<<"Base Constructor"<<std::endl;
	}
    virtual ~Base()
	{
		std::cout<<"Base Destructor"<<std::endl;
	}
};

class Derived : public Base
{
	int *ptr;
	public:
	Derived(int i) : Base(i)
	{
		std::cout<<"Derived Constructor"<<std::endl;
		ptr = new int [100];
	}
	~Derived()
	{
		std::cout<<"Derived Destructor"<<std::endl;
		delete[] ptr;
	}
};

int main()
{
// no problem in flow of constructor - destructor calls as its a direct object
//	Base bobj(10);
//	Derived dobj(10);

	Base *baseptr = new Derived(10);
    //delete internally results into invoking destructor. Compiler checks the type of pointer and then verifies if destructor of that type is virtual or not. If not virtual resolve the address at compile time with respective types destructor o.w put the code in place for invoking destructor at runtime of pointed type(if pointed type is dervied then reverse order of destructor invocation will be implicitly followed).
	delete baseptr;
}
