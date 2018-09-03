#include <bits/stdc++.h>

using namespace std;

int main()
{
#if ATOMIC
    atomic<int> cnt(0);
#else
    int cnt = 0;
#endif
    auto f = [&]{cnt++; cout<<cnt<<endl;};
    std::thread t1{f}, t2{f}, t3{f};
    while(cnt < 3)
        cout<<"main:"<<cnt<<endl;
//    this_thread::sleep_for(chrono::milliseconds(5000));
    t3.join();
    t1.join();
    t2.join();
    return 0;
}
