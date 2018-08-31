#include "base1.h"

Base1::Base1() : property(200000)
{

}

float Base1::GetProperty() const
{
	return property;
}

float Base1::getWadapav() const
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
	return property;
}

float Base1::getShira()
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
	return property;
}

void Base1::Display()
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
}
	
float Base1::getPoha() 
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
	return property;
}
	
float Base1::getLadu() 
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
	return property;
}
	
float Base1::getBhaji() 
{
	std::cout<<"Base1::"<<__FUNCTION__<<std::endl;
	return property;
}
