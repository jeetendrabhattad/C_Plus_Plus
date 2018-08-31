#include <iostream>

class Base
{
	public:
	virtual void Display() = 0;
/*	{
		std::cout<<"Display";
	}*/
};

class Derived : public Base
{
	public:
	void Display()
	{

	}
};
int main()
{
	Derived obj;
}
