#include <iostream>
// Four Types of casting operators in C++
// i) static_cast :- it is same as compile time type-casting. It performs non-polymorphic type-casting.
//	   General Form :- static_cast<target-type>(expression)
// ii) dynamic_cast :- performs a run-time cast that verifies the validity of a cast. 
//			General Form :- dynamic_cast<target-type>(expression)
//			Target type must be pointer or a reference type.
//			The expression must be polymorphic i.e it must contain virtual functions.

class Base
{
	public:
	virtual void Display()
	{
		std::cout<<"Display of Base\n";
	}
};

class Derived : public Base
{
	public:
	int b;
	void Display()
	{
		std::cout<<"Display of Derived\n";
	}
	virtual void OnlyDerived()
	{
		std::cout<<"OnlyDerived\n";
	}
	void Test(){
		std::cout<<"Derived Test\n";
	}
};

class Test
{
	int i, j , k;
	public:
	void TestDisplay()
	{
		i = j = k = 10;
		std::cout<<"Test Display Called "<<i<<":"<<j<<":"<<k<<std::endl;
	}
};

int main()
{
	Base *ptr;
	Derived dObj;
	ptr = &dObj;
	ptr->Display();
	static_cast<Derived*>(ptr)->OnlyDerived();
	static_cast<Derived*>(ptr)->Test();
	const Derived* cdObj = &dObj;
	//cdObj->b = 100;
	// changing value of constant object using const_cast
	const_cast<Derived*>(cdObj)->b = 100;
	// Reinterpreting Base Pointer as Test Object; 
	Test *obj = reinterpret_cast<Test*>(ptr);
	obj->TestDisplay();
	return 0;
}
#if 0

int main()
{
	Base bobj;
	Derived dobj;	
	Base *bPtr = &dobj;
	
	// converting Base* to Derived*
	Derived *ptrDerived = dynamic_cast<Derived*>(bPtr);
	if(ptrDerived)
	{
		std::cout<<"Converting Base* to Derived* Successful\n";
		ptrDerived->Display();
	}
	else
		std::cout<<" Failed to Convert\n";

	// converting Base* to Derived*
	static_cast<Derived*>(bPtr)->Display();

	const Derived* cdObj = &dobj;
//	cdObj->b = 100;
	// changing value of constant object using const_cast
	const_cast<Derived*>(cdObj)->b = 100;
	
	// Invalid dynamic_cast, results into segmentation fault, compile time warning is issued
	// warning: dynamic_cast of ‘Base bobj’ to ‘class Derived*’ can never succeed
	Derived* ptrObj = dynamic_cast<Derived*>(&bobj);
	if( NULL == ptrObj )
	{
		std::cout<<"Type Casting Failed\n";
	}
	
	// Reinterpreting Base Pointer as Test Object; 
	Test *obj = reinterpret_cast<Test*>(bPtr);
	obj->TestDisplay();
	return 0;
}
#endif
