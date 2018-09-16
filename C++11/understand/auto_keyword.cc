#include <bits/stdc++.h>
using namespace std;
void callback(int i)
{
    cout<<"Value = "<<i<<endl;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(auto it = v.begin() ; it != v.end() ; it++)
    //for(std::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
        cout<<*it<<endl;
    //using for each loop
    for(auto x : v)
        cout<<x<<endl;
    for_each(v.begin(), v.end(), callback);
    //how for_each internally works
    for( int i = 0 ; i < v.size() ; i++)
        callback(v[i]);
}
