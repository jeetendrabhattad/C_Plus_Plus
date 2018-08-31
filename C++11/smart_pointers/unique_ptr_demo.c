/*
    Smart Pointers eliminate the need of explicit invocation of delete for dynamically created object.
    Unique Pointers are one of the type of smart pointers where if you are sure that you are going to create only one instance and that instance is not 
    to be shared between the objects then make such object as unique. By making it unique assigning existing unique_ptr to other variable results into
    compile time error.
    Unique pointers can be moved i.e one can create another unique pointer from existing one after which existing one no longer points to the memory.
    Unique pointers don't have to maintain the reference count as at a time only one reference will exist in any case.

    Passing unique_ptr to a function :
    a. By Value : results into an error as : unqiue_ptr class has marked the implementation of assignment operator as delete :
                       unique_ptr(const unique_ptr&) = delete;
    b. By Reference : works fine.
*/
#include <bits/stdc++.h>
#include <memory>

using namespace std;

class TestUnique
{
    int i;
    public:
    TestUnique()
    {
        cout<<"TestUnique Constructor:"<<endl;
    }
    ~TestUnique()
    {
        cout<<"TestUnique Destructor:"<<endl;
    }
    void foo()
    {
        cout<<"Inside Foo"<<endl;
    }
};

void foo(unique_ptr<TestUnique>& obj)
{
   obj->foo();
}
int main()
{
    unique_ptr<TestUnique> obj1;
    {
//      unique_ptr<TestUnique> obj = make_unique<TestUnique>(); //supported C++14 onwards
//      unique_ptr<TestUnique> obj1 = new TestUnique(); // Not allowed as constructor is explicit
        unique_ptr<TestUnique> obj2(new TestUnique());
        foo(obj2);
        auto obj1 = move(obj2);
//      obj1 = obj; // Not allowed as assignment operator is marked delete in implementation
        if(obj2)
        {
            cout<<"Obj2 is alive...\n";
        }
        else
        {
            cout<<"Obj2 moved to Obj1...\n";
        }
        obj1->foo();
        obj1->foo();
    }
    return 0;
}
