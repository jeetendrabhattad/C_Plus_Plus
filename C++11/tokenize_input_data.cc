#include <bits/stdc++.h>

using namespace std;
void removeExtraCharacter(string& input, const char extra= ' ')
{
    string::iterator new_end = unique(input.begin(), input.end(), [&extra](const char &x, const char &y){
        return x == y && x == extra;        
    });
    input.erase(new_end, input.end());

    if(input[input.length() - 1]  == extra)
        input.pop_back();
    if(input[0] == extra)
        input.erase(0, 1);
}
vector<string> tokenizeInput(string& input, const char& delimiter)
{
    vector<string> result;

    size_t pos = input.find(delimiter);
    size_t i = 0;

    while(pos != string::npos)
    {
        result.push_back(input.substr(i, pos - i));
        i = pos + 1;
        pos = input.find(delimiter, i);
    }
    result.push_back(input.substr(i, min(pos, input.length()) - i + 1));
    return result;
}
int main()
{
    string input;
    cout<<"\nEnter Line:";
    getline(cin, input);
    cout<<"\nInput String:"<<input;
    removeExtraCharacter(input);
    cout<<"\nRemoved Spaces:"<<input<<endl;
    vector<string> data = tokenizeInput(input, ' ');
    cout<<"\nTokenized Data:";
    for(x : data)
        cout<<x<<std::endl;
    input = "\n\njeetendra\n\nbhattad\nsamartha\n\n\n";
    cout<<"\nInput String:"<<input;
    removeExtraCharacter(input,'\n');
    cout<<"\nRemoved Spaces/Extra Character:"<<input<<endl;
    data = tokenizeInput(input, '\n');
    cout<<"\nTokenized Data:";
    for(x : data)
        cout<<"Line:"<<x<<std::endl;

    return 0;
}
