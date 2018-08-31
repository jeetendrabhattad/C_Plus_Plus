#ifndef _BASE_2_H_
#define _BASE_2_H_
#include <iostream>
class Base2
{
	int property;

	public:
	Base2();
	virtual float getPoha() ;
	virtual float getUpma() ;
	virtual float getBhaji() ;
	virtual float getBurger() ;
	void Display();
	float GetProperty() const;
};
/*
	Vtable of Base2 contains following entries
	Base2::getPoha
	Base2::getUpma
	Base2::getBhaji
	Base2::getBurger
*/
#endif
