#include "shape.h"
#include <iostream>

Shape::Shape()
{
	std::cout<<"Shape Constructor\n";
}

Shape::~Shape()
{
	std::cout<<"Shape Destructor\n";
}

void Shape::Draw()
{
	std::cout<<"Shape Draw Method\n";	
}
