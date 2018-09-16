#include <iostream>
using namespace std;
class Base
{
	public:
	virtual void Display() = 0;
};
// this is useless as object of the class cannot be created and this method cant be invoked directly.
// concrete class of Base can invoke the body of pure virtual method provided by Base.
void Base::Display()
{
    std::cout<<"Pure Virtual Display"<<endl;
}

class Derived : public Base
{
	public:
	void Display()
	{
        cout<<"Derived Display\n";
        Base::Display();
	}
};
int main()
{
	Derived obj;
    obj.Display();
    obj.Base::Display();
    //Base bObj; -- this itself is not possible hence invoking method Display is not possible for object of type base.
}
