#include "InstanceControl.h"
#include <iostream>

InstanceControl* InstanceControl::pInstance = NULL;
int InstanceControl::NoOfInstances = 0;

InstanceControl::InstanceControl()
{
	std::cout<<"Constructor\n";
}

InstanceControl::~InstanceControl()
{
	std::cout<<"Destructor\n";
}

void InstanceControl::ShowContacts()
{
	std::cout<<"Displaying List of Contacts\n";
}

void InstanceControl::ShowMusic()
{
	std::cout<<"Displaying List of Musics\n";
}

InstanceControl* InstanceControl::GetInstance()
{
	std::cout<<"Static Method to create object\n";
	if(NoOfInstances < 10)
	{
		std::cout<<"Object with count "<<NoOfInstances+1<<" created\n";
		NoOfInstances++;
		return new InstanceControl;
	}
	return NULL;
}

void InstanceControl::DeleteInstance()
{
	delete pInstance;
	pInstance = NULL;
}
