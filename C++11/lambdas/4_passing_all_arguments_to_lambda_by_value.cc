#include <bits/stdc++.h>

using namespace std;

struct isMultiplier
{
    isMultiplier(int m) : mul(m){}
    bool operator()(int x)
    {
        return 0 == x%mul;
    }    
    int mul;
};
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};

    int mul = 3;
    
    int count_function = count_if(begin(v), end(v), isMultiplier(mul));
    std::cout<<"Count of Event Numbers Using Struct function:"<<count_function<<endl;

    int count_lambda = count_if(begin(v), end(v), [=](int x){return 0 == x%mul;});
    std::cout<<"Count of Event Numbers Using Lambda:"<<count_lambda<<endl;
    return 0;
}
