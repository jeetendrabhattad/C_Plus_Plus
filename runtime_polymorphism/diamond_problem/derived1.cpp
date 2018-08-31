#include "base.h"
#include "derived1.h"

float Derived1::getLadu()
{
	std::cout<<"Derived1::"<<__FUNCTION__<<std::endl;	
}

float Derived1::getBhaji()
{
	std::cout<<"Derive1::"<<__FUNCTION__<<":"<<__LINE__<<std::endl;
}
