#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "base1.h"
#include "base2.h"

class Derived : public Base1, public Base2
{
	public:
	float getWadapav() const;
	float getPoha() ;
	float getUpma() ;
	virtual float getLimbuSharbat() ;
};

#endif
