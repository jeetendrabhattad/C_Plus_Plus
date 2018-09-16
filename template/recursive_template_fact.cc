#include <iostream>
using namespace std;

template<int N>
struct Fact
{
    enum{
        value = N*Fact<N-1>::value
    };
};

template<>
struct Fact<1>{
    enum{
        value = 1
    };
};

template<>
struct Fact<0>{
    enum{
        value = 1
    };
};

constexpr int fact(int n)
{
    return n < 1 ? 1 : n*fact(n-1);
}
int main()
{
    cout<<Fact<7>::value<<endl;
#if 0
    //below stuff cannot evaluate as no is not known at compile time and templates evaluate at compile time.
    //C++11 added constexpr which can be used to achieve the following behavior
    int no;
    cin>>no;
    cout<<Fact<no>::value<<endl;
#endif
    cout<<"constexpr fact(5):"<<fact(5)<<endl;
    int no;
    cin>>no;
    cout<<"constexpr fact("<<no<<") = "<<fact(no)<<endl;

    return 0;
}

