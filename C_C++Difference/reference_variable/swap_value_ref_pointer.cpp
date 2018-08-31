#include <iostream>
//Pass By Value
double SwapByValue(double no1, double no2)
{
	double temp = no1;
	no1 = no2;
	no2 = temp;
}
//C++ reference variable
double Swap(double &no1, double &no2)
{
	double temp = no1;
	no1 = no2;
	no2 = temp;
}
//Pass by Pointer (reference)
double Swap(double *no1, double *no2)
{
	double temp = *no1;
	*no1 = *no2;
	*no2 = temp;
}

int main()
{
	double no1=12.12, no2=13.12;

	std::cout<<no1<<":"<<no2<<std::endl;
	SwapByValue(no1, no2);
	std::cout<<no1<<":"<<no2<<std::endl;
	Swap(no1, no2);
	std::cout<<no1<<":"<<no2<<std::endl;
	Swap(&no1, &no2);
	std::cout<<no1<<":"<<no2<<std::endl;
}
