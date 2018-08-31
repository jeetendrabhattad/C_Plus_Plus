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
//	Base bobj;
//	Derived dobj;

	Base *baseptr = new Derived(10);

	delete baseptr;
}
