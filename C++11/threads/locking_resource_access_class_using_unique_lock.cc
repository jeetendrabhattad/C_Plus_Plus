//g++ locking_resource_access_class_using_unique_lock.cc -std=c++11 -pthread -DLOCK
// unique lock can be moved but lock_guard can't be. unique lock has a performance overhead as it has to do additional housekeeping.
#include <bits/stdc++.h>
using namespace std;

class Logger
{
    private:
    std::mutex _mu;
    ofstream   _f;
    public:
    
    Logger(string fname ="log.txt")
    {
        _f.open(fname);
    }

    void SharePrint(const string& id, const int& value)
    {
#if LOCK
        std::unique_lock<mutex> guard(_mu);
#elif DEFERRED_LOCK
        std::unique_lock<mutex> guard(_mu, defer_lock);
        guard.lock();
#endif
        _f<<"id:"<<id<<"value:"<<value<<endl;
#if LOCK or DEFERRED_LOCK
        guard.unlock();
#endif
    }
};

void worker(Logger& log)
{
    int i = 0;
    while(i < 100)
    {
        log.SharePrint("worker", i+1);
        i++;
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
#if LOCK
    Logger log("unique_lock_log.txt");
#else
    Logger log("log_no_lock.txt");
#endif
    thread t1(worker, ref(log));

    int i = 101;
    while(i < 200)
    {
        log.SharePrint("main", i+1);
        i++;
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    t1.join();
    return 0;
}
