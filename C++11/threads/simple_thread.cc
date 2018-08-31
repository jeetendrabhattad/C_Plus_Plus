//to compile ensure : -std=c++11 -pthread are passed as an argument to g++
#include <bits/stdc++.h>

using namespace std;

void Worker()
{
    cout<<"Worker Started.\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Worker Done\n";
}

int main()
{
    cout<<"Main:Creating Thread.\n";
    thread t1(Worker);

    cout<<"Main:Waiting for Thread to Finish.\n";
    t1.join();
    cout<<"Main:Worker Thread execution Done.\n";
    return 0;
}
