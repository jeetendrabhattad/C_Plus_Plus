#include "square.h"
#include <iostream>

Square::Square(int len) : length(len) {
	std::cout<<"Square Constructor\n";
}

Square::~Square(){
	std::cout<<"Square Destructor\n";
}

void Square::SetLength( const int len ) {
	std::cout<<"Square::SetLength\n";
	length = len;
}

void Square::Draw() {
	std::cout<<"Square::Draw\n";
}
