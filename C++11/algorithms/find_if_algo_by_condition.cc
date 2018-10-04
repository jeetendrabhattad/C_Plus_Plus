#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1,2,33,4,5,6,11,44,33};

    //find first multiple of 11
    auto found = find_if(begin(v), end(v), [](int x){return x%11 == 0;});

    if(found != end(v))
        cout<<"Found :"<<*found<<endl;
}
