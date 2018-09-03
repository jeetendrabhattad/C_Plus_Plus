#include <bits/stdc++.h>

using namespace std;

int add(int a, int b)
{
    return a+b;
}

int main()
{
//    future<int> fu = std::async(add, 10, 20);//thread created
//    future<int> fu = std::async(launch::async, add, 10, 20);//thread created

    future<int> fu = std::async(launch::deferred, add, 10, 20);//no thread created on invocation of get the call gets invoked in this thread context

    int data = fu.get();//waits until the thread finishes. Further call will result into crash.

    cout<<"Received Data from Thread : "<<data<<endl;

    return 0;
}
