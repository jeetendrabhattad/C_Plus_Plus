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
        std::lock_guard<mutex> guard(_mu);
#endif
        _f<<"id:"<<id<<"value:"<<value<<endl;
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
    Logger log;
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
