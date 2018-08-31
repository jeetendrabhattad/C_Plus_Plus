#include "base.h"
#include "derived2.h"

Derived2::Derived2() : property(10000000)
{

}

float Derived2::getWadapav() const
{
	std::cout<<"Derived2::"<<__FUNCTION__<<std::endl;
	return property;
}
	
void Derived2::getSandwich()
{
	std::cout<<"Derived2::"<<__FUNCTION__<<std::endl;
}

void Derived2::CalculateProfit()
{
	std::cout<<"Derived2::"<<__FUNCTION__<<std::endl;
}
