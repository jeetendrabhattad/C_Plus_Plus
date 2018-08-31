#include <iostream>

#if 0
float add(float no1, float no2)
{
	return no1 + no2;
}

float add(float no1, float no2, float no3)
{
	return no1+no2+no3;
}
#endif

int add(int no1, int no2)
{
	return no1+no2;
}

float add(float no1, int no2)
{
	return no1+no2;
}

float add(int no1, float no2=1.2) //default argument
{
	std::cout<<no1<<":"<<no2<<std::endl;
	return no1+no2;
}
/*
float add(int no1)
{
	return no1;
}*/
/*int add(float no1, float no2)
{
	return no1+no2;
}*/
/*
float add(float a, float b, float c =0, float d =0, float e=0)
{
	std::cout<<a<<":"<<b<<":"<<c<<":"<<d<<":"<<e<<std::endl;
	return a+b+c+d+e;
}

float add(double a, double b, double c =0, double d =0, double e=0)
{
	std::cout<<a<<":"<<b<<":"<<c<<":"<<d<<":"<<e<<std::endl;
	return a+b+c+d+e;
}*/
int main()
{
	add(10, 20.3f);
	add(10);
	add(10, 20);
	add(10.0f, 20);
//	add(10.0f, 20.0f, 30.0f);
//	add(10.0f, 20.0f, 30.0f);
//	add(10.0, 20.0, 30.0, 40.0);
//	add(10.0, 20.0, 30.0, 40.0, 50.0);
}
