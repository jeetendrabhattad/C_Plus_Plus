#include <bits/stdc++.h>

using namespace std;

class ConversionConstructor
{
    int iData;
    public:
    explicit ConversionConstructor(int i) : iData(i)
    {
        cout<<"Constructor:"<<i<<endl;
    }
    ~ConversionConstructor()
    {
        cout<<"Destructor:"<<iData<<endl;
    }
    ConversionConstructor operator=(const int data)
    {
        this->iData = data;
        cout<<"Explicit Assignment:"<<iData<<endl;
        return *this;
    }
    operator int()//conversion function to convert object to primitive int.
    {
        cout<<"Converting to int:"<<iData<<endl;
        return this->iData;
    }
};
int main()
{
    ConversionConstructor c1(10);
    c1 = 40;//c1.operator=(40)

    int i = c1;//i.operator=(c1) -- this is not possible. In this case c1.operatorint() i.e conversion function gets invoked.
    return 0;
}
