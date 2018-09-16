#include <iostream>

using namespace std;
//override_understand.cc:19:7: error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derived’
//class Base final
class Base
{
    public:
    virtual void Interesting()
    {
        cout<<"Base::Interesting\n";
    }
    //method has to be virtual as it needs to be added to vtable to have polymorphic behavior but derived classes are to be restricted for not overriding the behavior of base class method hence make it final.
    virtual void DontOverride() final
    {
        cout<<"Base::DontOverride\n";
    }
};

class Derived : public Base
{
    public:
    //apply override keyword in Derived classes for methods which are to be over-ridden.
    //override keyword performs prototype exact match for respevtive methods with base class methods
    virtual void Interesting() override
    {
        cout<<"Derived::Interesting "<<endl;
    }
    //override_understand.cc:14:18: error: overriding final function ‘virtual void Base::DontOverride()’
    #if 0
    void DontOverride()
    {
        cout<<"Derived::DontOverride\n";
    }
    #endif
};

int main()
{
    Derived obj;
    Base *ptr = &obj;
    ptr->Interesting();
    return 0;
}
