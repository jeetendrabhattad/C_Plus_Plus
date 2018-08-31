#include <iostream>

class Base
{
	public:
	int i;
	char ch;
};

class Derived : public Base
{
	public:
	int i;
	float ch;
};

int main()
{
	Base b;
	Derived d;
	d.i = 10;
	d.ch = 2.3;

	b.i = 20;
	b.ch = 2.5;

	d.Base::i = 25;
}
