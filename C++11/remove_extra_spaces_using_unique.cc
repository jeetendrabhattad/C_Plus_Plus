#include <bits/stdc++.h>

using namespace std;
void removeExtraSpaces(string& input)
{
    string::iterator new_end = unique(input.begin(), input.end(), [](const char &x, const char &y){
        return x == y && x == ' ';        
    });
    input.erase(new_end, input.end());

    if(input[input.length() - 1]  == ' ')
        input.pop_back();
    if(input[0] == ' ')
        input.erase(0, 1);
}
int main()
{
    string input;
    cout<<"\nEnter Line:";
    getline(cin, input);
    cout<<"\nInput String:"<<input;
    removeExtraSpaces(input);
    cout<<"\nRemoved Spaces:"<<input<<endl;
    return 0;
}
