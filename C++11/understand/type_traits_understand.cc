#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

struct A{};
struct B{ virtual void f(){}};
struct C:B{};

int main()
{
    cout<<"int:"<<has_virtual_destructor<int>::value<<endl;
    cout<<"int:"<<is_polymorphic<int>::value<<endl;
    cout<<"A:"<<is_polymorphic<A>::value<<endl;
    cout<<"B:"<<is_polymorphic<B>::value<<endl;
    cout<<"C:"<<is_polymorphic<C>::value<<endl;

    //array dimension and size
    typedef int array[][10][20];
    cout<<"rank of array:"<<rank<array>::value<<endl;
    cout<<"(0, dim):"<<extent<array, 0>::value<<endl;
    cout<<"(1, dim):"<<extent<array, 1>::value<<endl;
    cout<<"(2, dim):"<<extent<array, 2>::value<<endl;
    return 0;
}
