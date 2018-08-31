#include "child.h"

Child::Child()
{
	std::cout<<"Child's Constructor\n";
}
float Child::getWadapav() const
{
	std::cout<<"Child::"<<__FUNCTION__<<std::endl;
}

void Child::getIceCream()
{
	std::cout<<"Child::"<<__FUNCTION__<<std::endl;	
}
