#include "Singleton.h"
#include <iostream>

Singleton* Singleton::pInstance = NULL;

Singleton::Singleton()
{
	std::cout<<"Constructor\n";
}

Singleton::~Singleton()
{
	std::cout<<"Destructor\n";
}

void Singleton::ShowContacts()
{
	std::cout<<"Displaying List of Contacts\n";
}

void Singleton::ShowMusic()
{
	std::cout<<"Displaying List of Musics\n";
}

Singleton* Singleton::GetInstance()
{
	std::cout<<"Static Method to create object\n";
	if(NULL == pInstance)
	{
		pInstance = new Singleton();
	}

	return pInstance;
}

void Singleton::DeleteInstance()
{
	delete pInstance;
	pInstance = NULL;
}
