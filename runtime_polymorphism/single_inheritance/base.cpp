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
	std::cout<<"Base::"<<__FUNCTION__<<std::endl;
}

#if STANDALONE

int main()
{
	Base obj;
	std::cout<<"Size of Base Object is "<<sizeof(obj)<<std::endl;

	obj.getWadapav();
	obj.Display();

	Base *bPtr = &obj;
	bPtr->getWadapav();
	bPtr->Display();	

}

#endif
