#include <iostream>
using namespace std;
void foo(char* s)
{
    cout<<"Inside foo with char*\n";
}
void foo(int i)
{
    cout<<"Inside foo with int\n";
}
int main()
{
    //null_ptr.cc:15:13: error: call of overloaded ‘foo(NULL)’ is ambiguous
    //foo(NULL);
    foo(nullptr);// goes to pointer argument
    foo(0);
}
