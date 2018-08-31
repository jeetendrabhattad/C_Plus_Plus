#include <iostream>
#include <string.h>
using namespace std;
class A{
public:
	virtual int foo(void)=0;
	virtual ~A()=0;
};
int A::foo(void){
	int i=1;
	cout<<"Pure virtual function:: foo"<<endl;
}
A::~A(){
	cout<<"Pure virtual destructor. Base"<<endl;
}
class B:public A{
public:
	virtual int foo(void){
		cout<<"Pure virtual implementation in base"<<endl;
	}
	virtual ~B(){
		cout<<"Derived destructor"<<endl;
	}
};
int main(){
	A* ptr;
	ptr = new B();
	B b1;
	delete ptr;
}
