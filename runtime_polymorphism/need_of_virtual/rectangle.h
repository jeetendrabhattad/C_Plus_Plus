#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
	int length;
	int breadth;
	public:
	Rectangle(int len = 5, int bread = 10);
	~Rectangle();
	void SetLength( const int len );
	void SetBreadth( const int bread );
	void Draw();
};
#endif
