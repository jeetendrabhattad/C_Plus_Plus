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

    cout<<"Main:Detaching Thread.\n";
    t1.detach();
    //detach results into making thread daemon and hence main thread won't wait for execution to complete. Main thread should do some further processing
    //otherwise thread's activity might not be visible seen.
    //once detached cannot be attached again
    cout<<"Main:Sleeping for 2 seconds.\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<"Main:Wokeup from Sleep of 2 seconds.\n";
    return 0;
}
