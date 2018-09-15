#include <iostream>

using namespace std;

int main()
{
    //string path = "\\home\\narendra\\cplusplus";//c++03 style
    string path = R"(\home\narendra\cplusplus)";//c++11 raw string

    cout<<path<<endl;
    return 0;
}
