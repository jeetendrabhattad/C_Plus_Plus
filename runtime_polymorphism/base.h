#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
class Base
{
	int property;

	public:
	Base();
	virtual float getWadapav() const;
	virtual float getShira() ;
	void Display();
};
/* Vtable for Base
 * Base::getWadapav
 * Base::getShira
 */
#endif
