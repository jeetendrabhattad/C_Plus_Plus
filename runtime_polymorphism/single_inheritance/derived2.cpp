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


int main()
{
	Derived2 obj;
	obj.getWadapav();
    std::cout<<"Sizeof derived object:"<<sizeof(obj)<<std::endl;
	Base *ptr = &obj;
	ptr->getWadapav();//
	ptr->getShira();
    //ptr->getSandwich();
	//dynamic_cast<Derived2*>(ptr)->getSandwich();

	return 0;
}
