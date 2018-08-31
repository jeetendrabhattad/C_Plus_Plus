#include "derived.h"

	
float Derived::getWadapav() const
{
	std::cout<<"Derived::"<<__FUNCTION__<<std::endl;
	return Base1::GetProperty();
}

float Derived::getPoha() 
{
	std::cout<<"Derived::"<<__FUNCTION__<<std::endl;
	return Base2::GetProperty();
}
float Derived::getUpma() 
{
	std::cout<<"Derived::"<<__FUNCTION__<<std::endl;
	return Base1::GetProperty();
}
float Derived::getLimbuSharbat() 
{
	std::cout<<"Derived::"<<__FUNCTION__<<std::endl;
	return Base2::GetProperty();
}
