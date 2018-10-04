#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,5,5,1,2,4};

    auto result = find(begin(v), end(v), 5);

    while(result != end(v))
    {
        cout<<"Found :"<<*result<<endl;
        result = find(result+1, end(v), 5);//+1 required to find from the next position
    }
    return 0;
}
