/*
    If Interface user creates the Logger object but never invokes SharePrint method then it will result into un-necessarily opening the file and not using it.
    By applying Lazy Initialization Idiom we can open the file only when SharePrint method is invoked.
    But then on every invocation we don't want the file to be opened again and again. C++11 added call_once feature to fix such issues.
*/
#include <bits/stdc++.h>
using namespace std;

class Logger
{
    private:
    std::mutex _mu;
    ofstream   _f;
    once_flag  _flag;
    string _fname;
    public:
    
    Logger(string fname ="log.txt") : _fname(fname)
    {
    }

    void SharePrint(const string& id, const int& value)
    {
        std::call_once(_flag, [&](){
        cout<<"Opened File"<<endl;
        _f.open(_fname);});
        std::lock_guard<mutex> guard(_mu);
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
    Logger log;
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
