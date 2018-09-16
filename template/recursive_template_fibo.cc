#include <iostream>
using namespace std;

template<int N>
struct Fibo{
    enum{
        value = Fibo<N-1>::value + Fibo<N-2>::value
    };
};

template<>
struct Fibo<1>{
    enum{
        value = 1
    };
};

template<>
struct Fibo<0>{
    enum{
        value = 0
    };
};

int main()
{
    cout<<Fibo<15>::value<<endl;
}
