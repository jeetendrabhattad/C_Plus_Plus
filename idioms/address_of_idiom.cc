#include <bits/stdc++.h>

using namespace std;

class AddressOfUnaddressable
{
    public:
    double operator&() const
    {
        cout<<"operator & for AddressOfUnadressable"<<endl;        
        return 3.4;
    }
};
//C++03 solution
template<typename T>
T* addressOf(T& obj)
{
    return reinterpret_cast<T*>(& const_cast<char&>(reinterpret_cast<const volatile char &>(obj)));
}

int main()
{
    AddressOfUnaddressable obj;

    cout<<&obj<<endl; //instead of displaying address - displays 3.4 as operator& is overloaded by class.
    //Error for below line of code : address_of_idiom.cc:21:36: error: cannot convert ‘double’ to ‘AddressOfUnaddressable*’ in initialization
    //AddressOfUnaddressable *ptr = &obj;
    //C++03 solution
    cout<<"C++03:"<<addressOf(obj)<<endl;

    cout<<"C++11:"<<addressof(obj)<<endl;
    return 0;
}
