#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

//needs commenting to explain what it does, as the lines are more possibility of error is also more
int count_function(vector<int> v, int target)
{
    int count = 0;

    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == target)
            count++;
    }
    return count;
}

int main()
{
    vector<int> v = {1,2,3,4,5,3,2,1,2};
    cout<<"Count Function for presence of 2:"<<count_function(v, 2)<<endl;

    int counts = std::count(v.begin(), v.end(), 2);
    cout<<"Count algorithm count(v.begin(), v.end()) for presence of 2:"<<counts<<endl;

    //returns the same way as v.begin(), v.end()
    counts = std::count(begin(v), end(v), 2);
    cout<<"Count algorithm count(begin(v), end(v)) for presence of 2:"<<counts<<endl;
    
    //begin(v), end(v) works on C style arrays as well
    int arr[] = {1,2,3,4,5,3,2,1,2};
    counts = std::count(begin(arr), end(arr), 2);
    cout<<"Count algorithm count(begin(v), end(v)) for presence of 2 on C style array:"<<counts<<endl;
    
    return 0;
}
