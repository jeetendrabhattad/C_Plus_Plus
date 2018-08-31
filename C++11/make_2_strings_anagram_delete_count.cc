#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int first_string_chars[26]={0};
    int second_string_chars[26]={0};
    
    for(auto ch : a)
    {
        ch = tolower(ch);
        first_string_chars[ch-97]++;
    }
    for(auto ch : b)
    {
        ch = tolower(ch);
        second_string_chars[ch-97]++;
    }
    int delete_count = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(first_string_chars[i] == second_string_chars[i])
            continue;
        delete_count += abs(first_string_chars[i]-second_string_chars[i]);
    }
    return delete_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

