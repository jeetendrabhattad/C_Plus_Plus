#ifndef _DERIVED_2_H_
#define _DERIVED_2_H_
#include"base.h"
class Derived2 : public Base
{
	float property;
	public:
	Derived2();
	float getWadapav() const;
	virtual void getSandwich();
	void CalculateProfit(); 
};
/* Vtable for Derived2
 * Derived2::getWadapav
 * Base::getShira
 * Derived2::getSandwich
 */
#endif
