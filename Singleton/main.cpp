#include "Singleton.h"
#include <iostream>

void SimulateSingleton()
{
	std::cout<<"Singleton Design Pattern Example\n";
	Singleton *s1 = Singleton::GetInstance();
	std::cout<<"Address of s1 is :"<<s1<<std::endl;
	s1->ShowContacts();
	Singleton *s2 = Singleton::GetInstance();
	std::cout<<"Address of s2 is :"<<s2<<std::endl;
	s2->ShowMusic();
	Singleton::DeleteInstance();	
#if CONTROL_ON_NO_OF_OBJECTS
	Singleton *s3 = Singleton::GetInstance();
	Singleton *s4 = Singleton::GetInstance();
	Singleton *s5 = Singleton::GetInstance();
	Singleton *s6 = Singleton::GetInstance();
	Singleton *s7 = Singleton::GetInstance();
	Singleton *s8 = Singleton::GetInstance();
	Singleton *s9 = Singleton::GetInstance();
	Singleton *s10 = Singleton::GetInstance();
	if(NULL == s10)
		std::cout<<"Some Problem in Logic Verify\n";
	Singleton *s11 = Singleton::GetInstance();
	
	if(NULL == s11)
		std::cout<<"Max object creation count reached\n";
#endif
}

int main()
{
	SimulateSingleton();
}
