#include "base.h"

Base::Base() : property(200000)
{

}

float Base::getWadapav() const
{
	std::cout<<"Base::"<<__FUNCTION__<<std::endl;
	return property;
}

float Base::getShira()
{
	std::cout<<"Base::"<<__FUNCTION__<<std::endl;
	return property;
}

void Base::Display()
{
	std::cout<<"Display of Base\n";
	std::cout<<"Base::"<<__FUNCTION__<<std::endl;
}
