//to compile ensure : -std=c++11 -pthread are passed as an argument to g++
#include <bits/stdc++.h>

using namespace std;

void WorkerDataByValue(int no)
{
    cout<<"WorkerDataByValue Started :"<<no<<":"<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"WorkerDataByValue Done\n";
}

void WorkerDataByReference(int &no)
{
    cout<<"WorkerDataByReference Started :"<<no<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    no = no*2;
    cout<<"WorkerDataByReference Done\n";
}

int main()
{
    cout<<"Main:Creating WorkerDataByValue Thread taking one argument as by value.\n";
    thread t1(WorkerDataByValue, 100);
    cout<<"Main:Waiting for WorkerDataByValue thread to Finish.\n";
    t1.join();

    int no = 100;
    #if 0
    //results into a compile time error as no is not passed using std::ref function.
    cout<<"Main:Creating WorkerDataByReference Thread taking one argument as by reference :"<<no<<endl;
    thread t2(WorkerDataByReference, no); 
    cout<<"Main:Waiting for WorkerDataByReference thread to Finish.\n";
    t2.join();
    cout<<"Value of no after thread WorkerDataByReference is done :"<<no<<endl; // value of "no" for main doesnt changes though it is accepted by reference in Thread function.
    #endif
    cout<<"Main:Creating WorkerDataByReference Thread taking one argument as by Actual Reference :"<<no<<endl;
    thread t3(WorkerDataByReference, ref(no)); //ref methods create a reference and this results into sharing of "no" between thread and main thread.
    cout<<"Main:Waiting for WorkerDataByReference thread to Finish.\n";
    t3.join();
    cout<<"Value of no after thread WorkerDataByReference is done :"<<no<<endl; // value of "no" for main changes as ref function is invoked while passing argument on thread creation..
   
    cout<<"How many threads can be created ? Know the Hardware concurrency: "<<thread::hardware_concurrency()<<endl; 
    return 0;
}
