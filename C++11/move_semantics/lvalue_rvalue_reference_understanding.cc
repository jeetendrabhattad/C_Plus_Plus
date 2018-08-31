#include <bits/stdc++.h>

using namespace std;

void Print(int& i)
{
    cout<<"Updating Reference "<<i<<" to 100."<<endl;
    i = 100;
}

void Print(int&& i)
{
    cout<<"Overloaded Print with rvalue reference as an argument."<<i<<endl;
}

void Show(int&& i)
{
    cout<<"Argument by rvalue reference:"<<i<<endl;
    i = 200;
    cout<<"Argument by rvalue reference in Show:"<<i<<endl;
}

template <typename T>
void Test(T &&temp)
{
    cout<<"Type of parameter is :"<<typeid(T).name()<<endl;
}

int main()
{
    int i = 10;

    int& iLvalueRef = i; // The iLvalueRef refers to the same memory of i i.e it is an alias name of i. Such references are known as lvalue references
    cout<<"Before updating Lvalue reference:"<<i<<endl;
    Print(i);
    cout<<"Updated Lvalue Reference inside function:"<<i<<endl;
    int&& iRvalueRef = 10;//The iRvalueRef is reference to the value 10 which is an rvalue hence it is known as rvalue reference.
    cout<<"Before updating Rvalue reference:"<<iRvalueRef<<endl;
    Print(iRvalueRef);
    cout<<"Updated Rvalue Reference inside function:"<<iRvalueRef<<endl;

    //both the calls result into an error as show is expecting an rvalue as an argument but passed are the lvalue's 
    //Show(i);
    //Show(iRvalueRef);
    Show(10);
    Print(100);

    Test(10);
    Test(iLvalueRef);
    Test(iRvalueRef);
    return 0;
}
