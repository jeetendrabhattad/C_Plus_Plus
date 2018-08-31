/*
    Smart Pointers eliminate the need of explicit invocation of delete for dynamically created object.
    Shared Pointers are one of the type of smart pointers where if you want to share the same instance across objects then make such object as shared. 
    By making it shared_ptr assigning existing shared_ptr to other variable results into increasing the reference count.
    Shared pointers can be moved i.e one can create another shared pointer from existing one after which existing one no longer points to the memory.
    Shared pointers maintain the reference count, as and when an oject goes out of scope reference count drops by 1. When it reaches 0 the destructor
    for the object gets invoked.

    Passing shared_ptr to a function :
    a. By Value : results into increasing reference count
    b. By Reference : doesn't increases reference count

    weak pointers are type of shared pointers which don't increase the reference count.
*/
#include <bits/stdc++.h>
#include <memory>

using namespace std;

class TestShared
{
    int i;
    public:
    TestShared()
    {
        cout<<"TestShared Constructor:"<<endl;
    }
    ~TestShared()
    {
        cout<<"TestShared Destructor:"<<endl;
    }
    void foo()
    {
        cout<<"Class Method Foo"<<endl;
    }
};

void foo(shared_ptr<TestShared> obj)
{
   obj->foo();
   cout<<" Foo Reference count:"<<obj.use_count()<<endl;
}

void bar(shared_ptr<TestShared>& obj)
{
   obj->foo();
   cout<<" bar Reference count:"<<obj.use_count()<<endl;
}
int main()
{
//      shared_ptr<TestShared> obj = make_shared<TestShared>(); //supported C++14 onwards
//      shared_ptr<TestShared> objn = new TestShared(); // Not allowed as constructor is explicit
        shared_ptr<TestShared> obj2(new TestShared());
        cout<<"Reference count:"<<obj2.use_count()<<endl;
        foo(obj2);
        bar(obj2);
        cout<<"Reference count:"<<obj2.use_count()<<endl;
        auto obj1 = move(obj2);
//      obj1 = obj; // Not allowed as assignment operator is marked delete in implementation
        {
            auto obj3 = obj1; // increases the reference count
            obj3->foo();
            cout<<"Scope Reference count:"<<obj1.use_count()<<endl;
            weak_ptr<TestShared> obj_weak = obj1; //creating weak reference doesn't result into increasing the reference count.
            obj1->foo();
            cout<<"Weak Ref Scope Reference count:"<<obj1.use_count()<<endl;
            cout<<"Weak Ref owner_before:"<<obj1.owner_before(obj3)<<endl; //returns false as obj1 is not owner before obj3
            cout<<"Weak Ref owner_before:"<<obj2.owner_before(obj1)<<endl; //returns true as obj2 was owner before obj1 
        }
        // as obj3 goes out of scope reference count is reduced by 1.
        if(obj2)
        {
            cout<<"Obj2 is alive...\n";
        }
        else
        {
            cout<<"Obj2 moved to Obj1...\n";
        }
        obj1->foo();
        cout<<"At Exit Reference count:"<<obj1.use_count()<<endl;
    return 0;
}
