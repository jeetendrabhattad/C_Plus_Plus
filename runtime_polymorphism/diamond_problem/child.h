#include "derived1.h"
#include "derived2.h"

class Child : public Derived1, public Derived2
{
	public:
	Child();
	float getWadapav() const;
	virtual void getIceCream();
};
