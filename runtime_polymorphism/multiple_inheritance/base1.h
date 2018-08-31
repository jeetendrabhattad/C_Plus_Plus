#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
class Base1
{
	int property;

	public:
	Base1();
	virtual float getWadapav() const;
	virtual float getShira() ;
	virtual float getPoha() ;
	virtual float getLadu() ;
	virtual float getBhaji() ;
	void Display();
	float GetProperty() const;
};

/*
    Vtable of Base1 will have following entries
	Base1::getWadapav
	Base1::getShira
	Base1::getPoha
	Base1::getLadu
	Base1::getBhaji
*/
#endif
