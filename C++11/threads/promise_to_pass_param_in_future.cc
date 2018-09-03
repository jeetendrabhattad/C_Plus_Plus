#include <bits/stdc++.h>
//future and promise are movable not copyable
using namespace std;

int add(future<int> &f)
{
    int a = f.get();
    int b = 10;
    return a+b;
}

int main()
{
    promise<int> p;

    future<int> f = p.get_future();//no thread created on invocation of get the call gets invoked in this thread context

    future<int> fu = async(launch::async, add, ref(f));    

    this_thread::sleep_for(chrono::milliseconds(1000));

    p.set_value(100);
    //p.set_value(200);

    int data = fu.get();
    cout<<"Received Data from Thread : "<<data<<endl;

    return 0;
}
