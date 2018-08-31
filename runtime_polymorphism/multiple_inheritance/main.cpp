#include "derived.h"

int main()
{
	Base1* base1_obj;
	Base2* base2_obj;
	Derived derived_obj;
	derived_obj.Base1::getBhaji();	
	derived_obj.Base2::getBhaji();	
	std::cout<<"Size of Base1:-"<<sizeof(Base1)<<std::endl;
	std::cout<<"Size of Base2:-"<<sizeof(Base2)<<std::endl;
	std::cout<<"Size of Derived:-"<<sizeof(Derived)<<std::endl;

//base class 1 pointer pointing to derived object
	base1_obj = &derived_obj;
	
	base1_obj->getWadapav();
	base1_obj->getPoha();
	base1_obj->getLadu();
	base1_obj->getBhaji();
	base1_obj->getShira();
	dynamic_cast<Derived*>(base1_obj)->getUpma();
	dynamic_cast<Derived*>(base1_obj)->getLimbuSharbat();
	std::cout<<"Now its time to use base2's pointer\n";
//base class 2 pointer pointing to derived object
	base2_obj = &derived_obj;
	base2_obj->getPoha();
	base2_obj->getUpma();
	base2_obj->getBhaji();
	base2_obj->getBurger();
	static_cast<Derived*>(base2_obj)->getWadapav();
	dynamic_cast<Derived*>(base2_obj)->getLimbuSharbat();
}
