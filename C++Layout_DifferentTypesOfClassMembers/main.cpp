#include <iostream>
#include "CPPDeclarations.h"


void SimulateCPPDeclarations()
{
	CPPDeclarations defaultObject;// default constructor will be invoked
	int i(10); // int i = 10; this is an initialization
	i = 20;//assignment 
#if INITIALIZATION
	CPPDeclarations overloadedObject(10,20,30,40,50);
	std::cout<<"Displaying Values of Overloaded Object !!!!"<<std::endl;	
	std::cout<<"Public Variable Value is "<<overloadedObject.iPublic<<std::endl;	
	std::cout<<"Private Variable Value is "<<overloadedObject.GetPrivate()<<std::endl;	
	std::cout<<"Protected Variable Value is "<<overloadedObject.GetProtected()<<std::endl;	
	std::cout<<"Const Variable Value is "<<overloadedObject.GetConstant()<<std::endl;	
	std::cout<<"Reference Variable Value is "<<overloadedObject.GetByReference()<<std::endl;	
	std::cout<<"Mutable Variable Value is "<<overloadedObject.GetMutable()<<std::endl;	


	std::cout<<"Setting Values of Overloaded Object !!!!"<<std::endl;	
	overloadedObject.iPublic = 100;
	overloadedObject.SetPrivate(200);
	overloadedObject.SetProtected(300);
	overloadedObject.SetMutable(400);

	std::cout<<"Displaying Values of Overloaded Object !!!!"<<std::endl;	
	std::cout<<"Public Variable Value is "<<overloadedObject.iPublic<<std::endl;	
	std::cout<<"Private Variable Value is "<<overloadedObject.GetPrivate()<<std::endl;	
	std::cout<<"Protected Variable Value is "<<overloadedObject.GetProtected()<<std::endl;	
	std::cout<<"Const Variable Value is "<<overloadedObject.GetConstant()<<std::endl;	
	std::cout<<"Reference Variable Value is "<<overloadedObject.GetByReference()<<std::endl;	
	std::cout<<"Mutable Variable Value is "<<overloadedObject.GetMutable()<<std::endl;

	std::cout<<"static variable value is "<<CPPDeclarations::iStatic<<std::endl;
#else
	std::cout<<"Let's Understand Deep Copy v/s Shallow Copy"<<std::endl;
	CPPDeclarations::iStatic = 20;
	//defaultObject.iStatic = 20;
	CPPDeclarations copyObject(defaultObject); // resulted into invoking compiler provided copy constructor
	std::cout<<"Displaying Values of Copy Object !!!!"<<std::endl;	
	std::cout<<"Public Variable Value is "<<copyObject.iPublic<<std::endl;	
	std::cout<<"Private Variable Value is "<<copyObject.GetPrivate()<<std::endl;	
	std::cout<<"Protected Variable Value is "<<copyObject.GetProtected()<<std::endl;	
	std::cout<<"Const Variable Value is "<<copyObject.GetConstant()<<std::endl;	
	std::cout<<"Reference Variable Value is "<<copyObject.GetByReference()<<std::endl;	
	std::cout<<"Mutable Variable Value is "<<copyObject.GetMutable()<<std::endl;
#endif
}

int main()
{
	SimulateCPPDeclarations();
}
