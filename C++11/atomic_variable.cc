#include <bits/stdc++.h>

using namespace std;

class TestAtomic
{
    atomic<int> _i_atomic;
    //int _i_atomic;

    public:
    int getAtomic()
    {
        return _i_atomic;
    }
    void setAtomic(int v)
    {
        _i_atomic = v;
    }
};

void reader(TestAtomic &obj)
{
    while(1)
    {
        int val = obj.getAtomic();
        cout<<"Got "<<val<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        if(val == 99)
            break;
    }
}

void writer(TestAtomic &obj)
{
    int i = 0;
    while(i < 100)
    {
        obj.setAtomic(i);
        cout<<"Set "<<i<<endl;
        obj.setAtomic(i+1);
        cout<<"Set "<<i+1<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        obj.setAtomic(i+2);
        cout<<"Set "<<i+2<<endl;
        i++;
    }
}

int main()
{
    TestAtomic obj;
    thread t1(reader, ref(obj));
    thread t2(writer, ref(obj));

    t1.join();
    t2.join();
};
