#include "InstanceControl.h"
#include <iostream>

void SimulateInstanceControl()
{
	std::cout<<"InstanceControl Design Pattern Example\n";
	InstanceControl *s1 = InstanceControl::GetInstance();
	std::cout<<"Address of s1 is :"<<s1<<std::endl;
	s1->ShowContacts();
	InstanceControl *s2 = InstanceControl::GetInstance();
	std::cout<<"Address of s2 is :"<<s2<<std::endl;
	s2->ShowMusic();
	InstanceControl::DeleteInstance();	
#if CONTROL_ON_NO_OF_OBJECTS
	InstanceControl *s3 = InstanceControl::GetInstance();
	InstanceControl *s4 = InstanceControl::GetInstance();
	InstanceControl *s5 = InstanceControl::GetInstance();
	InstanceControl *s6 = InstanceControl::GetInstance();
	InstanceControl *s7 = InstanceControl::GetInstance();
	InstanceControl *s8 = InstanceControl::GetInstance();
	InstanceControl *s9 = InstanceControl::GetInstance();
	InstanceControl *s10 = InstanceControl::GetInstance();
	if(NULL == s10)
		std::cout<<"Some Problem in Logic Verify\n";
	InstanceControl *s11 = InstanceControl::GetInstance();
	
	if(NULL == s11)
		std::cout<<"Max object creation count reached\n";
#endif
}

int main()
{
	SimulateInstanceControl();
}
