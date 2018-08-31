/*
Description : A friend declaration in C++ gives complete access to the internals of a class. Friend declarations are, therefore, frowned upon because they break carefully crafted encapsulations. Friendship feature of C++ does not provide any way to selectively grant access to a subset of private members of a class.Friendship in C++ is an all-or-nothing proposition.

Providing selective access to a subset of members is desirable because the remaining (private) members can change interface if needed. 
It helps reduce coupling between classes. Attorney-Client idiom allows a class to precisely control the amount of access they give to their friends.

It is possible to have multiple attorney classes providing access to different sets of implementation details of the client.

An interesting case emerges where an attorney class serves as a mediator for several different classes and provides cohesive access to their 
implementation details. Such a design is conceivable in case of inheritance hierarchies because friendship in C++ is not inheritable, 
but private virtual function overrides in derived classes can be called if base's private virtual functions are accessible. 
*/

#include <bits/stdc++.h>

using namespace std;

class Client
{
    private:
    void foo(){
        cout<<"foo of Client"<<endl;
    }
    void print(int a){
        cout<<"print of Client:"<<a<<endl;
    }
    
    //don't want this method to be accessed by friend class bar
    void bar(){
        cout<<"bar of client"<<endl;
    }
    friend class Attorney;
};

//Attorney class which declares Bar as friend and wraps access to foo & print method of Client.
class Attorney
{
    private:
    static void access_foo(Client &obj){
        cout<<"Attorney::access_foo"<<endl;
        obj.foo();
    }
    static void access_print(Client &obj, int val){
        cout<<"Attorney::access_print"<<endl;
        obj.print(val);
    }
    friend class Bar;
};

class Bar
{
    Client cObj;
    public:
    void AccessFoo()
    {
        Attorney::access_foo(cObj); 
    }
    void AccessPrint()
    {
        Attorney::access_print(cObj, 10);
    }
};

int main()
{
    //Bar able to access Client object's foo & print private members of Client via Attorney. As Attorney has not exposed private method bar, Bar object cannot invoke the same.
    Bar bObj;
    bObj.AccessFoo();
    bObj.AccessPrint();
    return 0;
}
