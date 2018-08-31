#include <iostream>
#include <stdio.h>
#if TEMPLATE
template <typename T>
T add(T a, T b)
{	
	std::cout<<"Add Template "<<__FUNCTION__<<std::endl;
	return a+b;
}
#else
int add( const int no1, const int no2)
{
	std::cout<<"Add Integer\n";
	return no1+no2;
}

float add( const float no1, const float no2)
{
	std::cout<<"Add Float\n";
	return no1+no2;
}

double add( const double no1, const double no2)
{
	std::cout<<"Add Double\n";
	return no1+no2;
}
#endif
int main()
{
	std::cout<<add(10, 20)<<std::endl;
	std::cout<<add(10.05f, 5.4f)<<std::endl;
	std::cout<<add(10.05, 5.4)<<std::endl;
}
