#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(int len, int bread) :
	length(len),
	breadth(bread)
{
	std::cout<<"Rectangle Constructor\n";
}
Rectangle::~Rectangle()
{
	std::cout<<"Rectangle Destructor\n";
}

void Rectangle::SetLength( const int len ){
	std::cout<<"Rectangle::SetLength\n";
	length = len;
}

void Rectangle::SetBreadth( const int bread ){
	std::cout<<"Rectangle::SetBreadth\n";
	breadth = bread;
}

void Rectangle::Draw(){
	std::cout<<"Rectangle::Draw\n";
}
