#include <iostream>

class Base
{
	public:
	virtual void Display()
	{
		std::cout<<"Display of Base\n";
	}
};

class Derived : public Base
{
	public:
	int b;
	void Display()
	{
		std::cout<<"Display of Derived\n";
	}
};

class Test
{
	public:
	void DisplayI()
	{
		std::cout<<"Display of Test\n";
	}
};

int main()
{
	Base bobj;
	Derived dobj;	
	Base *bPtr = &dobj;
	
	Test *obj = reinterpret_cast<Test*>(bPtr);
	obj->DisplayI();
	dynamic_cast<Derived*>(bPtr)->Display();

	static_cast<Derived*>(bPtr)->Display();

	const Derived* cdObj = &dobj;
//	cdObj->b = 100;
	const_cast<Derived*>(cdObj)->b = 100;

	
	return 0;
}
