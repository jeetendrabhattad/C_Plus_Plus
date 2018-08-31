#include "square.h"
#include "rectangle.h"
#include <iostream>

int main()
{
	Shape shapeObj;
	shapeObj.Draw();

	Square sqObj;
	sqObj.Draw();

	Rectangle rectObj;
	rectObj.Draw();

	Shape *shapePtr = &shapeObj;
	shapePtr->Draw();

	shapePtr = &sqObj;
	shapePtr->Draw();
	
	shapePtr = &rectObj;
	shapePtr->Draw();

	std::cout<<"Size of Shape Object will be :-"<<sizeof(Shape)<<std::endl;	
}
