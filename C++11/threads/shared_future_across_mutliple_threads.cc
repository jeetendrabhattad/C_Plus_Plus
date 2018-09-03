#include <bits/stdc++.h>
//future and promise are movable not copyable
using namespace std;

int Process(shared_future<int> f)
{
    int data = f.get();
    cout<<this_thread::get_id()<<":"<<data<<endl;
    return 0;
}
int main()
{
    promise<int> p;

    future<int> f = p.get_future();//no thread created on invocation of get the call gets invoked in this thread context

    shared_future<int> fs = f.share();

    future<int> fu = async(launch::async, Process, fs);    
    future<int> fu1 = async(launch::async, Process, fs);    
    future<int> fu2 = async(launch::async, Process, fs);    
    future<int> fu3 = async(launch::async, Process, fs);    

    this_thread::sleep_for(chrono::milliseconds(1000));

    p.set_value(100);

    return 0;
}
