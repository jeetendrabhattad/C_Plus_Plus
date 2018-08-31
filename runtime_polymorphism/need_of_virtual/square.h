#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
	int length;
	public:
	Square(int len = 5);
	~Square();
	void SetLength( const int len );
	void Draw(); // override
};
#endif
