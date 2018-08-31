#include <bits/stdc++.h>

using namespace std;

mutex mu;

void shared_print(string msg, int val)
{
#if 0
    mu.lock();
    cout<<msg<<val<<endl; // if this line throws an exception, mutex will lock forever
    mu.unlock();
#endif
    lock_guard<mutex> guard(mu); //RAII - resource acquisition in initialization
    cout<<msg<<val<<endl; // if this line throws an exception, mutex will lock forever
}
void Worker()
{
    for(int i = -1 ; i > -100 ; i--)
        shared_print("Worker:", i);
}

int main()
{
    thread t1(Worker);
    for(int i = 0 ; i < 100 ; i++)
        shared_print("Main:", i);

    t1.join();
    return 0;
}
