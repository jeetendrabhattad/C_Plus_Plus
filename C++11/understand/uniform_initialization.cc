#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i = 6.3; //allowed
//uniform_initialization.cc:8:17: error: narrowing conversion of ‘6.2999999999999998e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
//    int j = {6.3};
    #if 199711 == __cplusplus
        cout<<"C++03 enabled\n";
        cout<<"Understanding Vector : create, intialize, access"<<endl;
        vector<int> v;
        for(int i = 1; i < 6 ; i++)
            v.push_back(i);
        for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
            cout<<*it<<endl;
        cout<<"Understanding Map"<<endl;
    #else
        cout<<"C++11 above enabled\n";
        cout<<"Understanding Vector : create, intialize, access"<<endl;
        vector<int> v = {1,2,3,4,5}; //allowed in C++11
        for(auto it = v.begin() ; it != v.end() ; it++)
            cout<<*it<<endl;
    #endif
    //for C++03
    return 0;
}
