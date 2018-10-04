#include <bits/stdc++.h>

using namespace std;

int count_odds(vector<int> v)
{
    int count = 0;
    for(auto x: v)
        if(x%2 != 0)
            count++;
    return count;
}

bool isOdd(int x)
{
    return x%2 != 0;
}

int main()
{
    vector<int> v = {1,2,3,4,5,5,3,2,1,12,14,12,16,78};

    int odd_count = count_odds(v);
    cout<<"Odd count via function:"<<odd_count<<endl;

    odd_count = count_if(begin(v), end(v), isOdd);
    cout<<"Odd count via count_if + function:"<<odd_count<<endl;

    odd_count = count_if(begin(v), end(v), [](int elem){ return elem%2 != 0;});
    cout<<"Odd count via count_if + lambda function:"<<odd_count<<endl;

    if(odd_count == v.size())
        cout<<"All the elements in the vector are odd\n";
    if(odd_count == 0)
        cout<<"None of the elements in the vector are odd\n";
    if(odd_count>0)
        cout<<"Few of the elements in the vector are odd\n";

    bool allof = all_of(begin(v), end(v), [](int x){return x%2!=0;});
    cout<<"all_of algorithm for checking all odd returns :"<<allof<<endl;

    bool noneof = none_of(begin(v), end(v), [](int x){return x%2!=0;});
    cout<<"none_of algorithm for checking none of odd returns :"<<noneof<<endl;

    bool anyof = any_of(begin(v), end(v), [](int x){return x%2!=0;});
    cout<<"any_of algorithm for checking any of odd returns :"<<anyof<<endl;
    
    map<int, int> months ={{1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6, 30}, {7,31}, {8, 31}, {9,30}, {10, 31}, {11,30}, {12, 31}};

    int longmonths = count_if(begin(months), end(months), [](pair<int, int> data){return data.second == 31;}); 
    cout<<"Total Long Months in year:"<<longmonths<<endl;
}
