#include <bits/stdc++.h>

using namespace std;

template<typename T>
void Print(initializer_list<T> args)
{
    for(auto x: args)
        cout<<x<<endl;
}

void PrintAny()
{
}

template<typename T, typename...Params>
void PrintAny(T a, Params... args)
{
    cout<<a<<":"<<typeid(a).name()<<endl;
    cout<<sizeof...(Params)<<endl;
    cout<<sizeof...(args)<<endl;
    PrintAny(args...);
}

int main()
{
    Print({1,2,3,4,5});
    //Print({1,2,3.5,4,5}); //vardict_template.cc:15:24: note:   deduced conflicting types for parameter ‘_Tp’ (‘int’ and ‘double’)
    PrintAny(1,2,3.5,4,5, "hello");
    
    return 0;
}
