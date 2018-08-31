/*
[]  Capture nothing (or, a scorched earth strategy?)
[&] Capture all alive variables by reference
[=] Capture all alive variables by making a copy(by value)
[=, &foo] Capture all alive variables by making a copy(by value), but capture variable foo by reference
[x] Capture variable x by making a constant copy; don't copy anything else
[this]  Capture the this pointer of the enclosing class
*/

#include <bits/stdc++.h>

using namespace std;

struct multiplierSum
{
    multiplierSum(int m) : mul(m){}
    int operator()(int x)
    {
        return mul += x;
    }    
    int mul;
};
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};

    int mul = 3;
    
    int sum = 0;
    //In Below Lambda Function all the arguments passed by reference to it hence accessing and updation work's fine.
    for_each(begin(v), end(v), [&](int x){if (x%mul) { sum+=x;}});
    std::cout<<"Sum of Numbers Using Lambda, passing all arguments by reference:"<<sum<<endl;
    
    //In Below Lambda Function all arguments will be passed by value and as mutable is specified it allows changing the variables passed by value 
    //but the original variables remain unchanged.
    sum = 0;
    for_each(begin(v), end(v), [=](int x) mutable {if (x%mul) { sum+=x;}});
    std::cout<<"Sum of Numbers Using Lambda, passing all arguments by value and specifying mutable:"<<sum<<endl;

    //selectively passing sum as reference and others by value.
    sum = 0;
    for_each(begin(v), end(v), [=,&sum](int x){if (x%mul) { sum+=x;}});
    std::cout<<"Sum of Numbers Using Lambda, passing all arguments by value except sum by reference:"<<sum<<endl;

    //creating a reference parameter to the existing parameter and using it for modification.
    sum = 0;
    for_each(begin(v), end(v), [=,&mySum = sum](int x){if (x%mul) { mySum+=x;}});
    std::cout<<"Sum of Numbers Using Lambda, creating local scope variable as a reference to outside variable:"<<sum<<endl;
    return 0;
}
