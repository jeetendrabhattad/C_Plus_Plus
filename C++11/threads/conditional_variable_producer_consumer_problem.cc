#include <bits/stdc++.h>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void producer()
{
    int count = 10;
    while(count > 0)
    {
        unique_lock<mutex> locker(mu);
        cout<<"Adding:"<<count<<endl;
        q.push_front(count);
        locker.unlock();
        cond.notify_one();
        this_thread::sleep_for(chrono::milliseconds(1000));
        count--;
    }
}

void consumer()
{
    int data = 0;
    while(data != 1)
    {
        unique_lock<mutex> locker(mu);
        cond.wait(locker, [&](){ return !q.empty();}); //spurious wake
        //cond.wait(locker);
        data = q.back();
        q.pop_back();
        locker.unlock();
        if(data > 7) // to simulate spurious wake (lambda function))
            this_thread::sleep_for(chrono::milliseconds(2000));
        cout<<"Read:"<<data<<endl;
    }
}

int main()
{
    thread produce(producer);
    thread consume(consumer);
    produce.join();
    consume.join();

    return 0;
}
