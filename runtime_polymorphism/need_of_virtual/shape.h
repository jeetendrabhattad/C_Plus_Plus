#ifndef BASE_H
#define BASE_H

class Shape
{
	public:
	Shape();
	~Shape();
	virtual void Draw();
	// Every object gets a pointer which points to Virtual Function Table
	// vptr i.e it is created per object
	// Vtable contains addresses of all virtual functions
	// one class has one vtable
};

#endif
