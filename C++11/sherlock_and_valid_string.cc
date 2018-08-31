#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int first_string_chars[26]={0};
    string valid = "YES";
    for(auto ch : s)
    {
        ch = tolower(ch);
        first_string_chars[ch-97]++;
    }
    int max_freq = 0;
    int j;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(first_string_chars[i])
        {
            max_freq = first_string_chars[i];
            j = i;
            break;
        }
    }
    int count = 0;
    for(int i = j ; i < 26 ; i++)
    {
        if(max_freq == first_string_chars[i] || first_string_chars[i] == 0)
            continue;
        count++;
    }
    if(count > 1)
        valid = "NO";
    return valid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    fout.close();

    return 0;
}

