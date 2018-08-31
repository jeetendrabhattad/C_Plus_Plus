#include <iostream>

// function overloading i.e compile-time polymorphism i.e false polymorphism
#if 0
Dependent on
1) Type of parameter & Sequence (they must not be same)
2) Number of parameters

Not Dependent on 
1) Return type
#endif

float add(float a)
{

}

int add(int a)
{


}

float add(int a, float b)
{
	return a+b;
}

int add(int a, int b, int c = 0, int d = 0)
{
	std::cout<<"Integer Addition\n";
	return a+b+c+d;
}

float add(float a, float b)
{
	std::cout<<"Float Addition\n";
	return a+b;
}

float add( float a, int b)
{

}

void add(char c)
{

}

void Demo(unsigned char c)
{

}

int main()
{
	std::cout<<"Add function of int is "<<add(10, 20.0f)<<std::endl;
	std::cout<<"Add function of float is "<<add(10.20f, 20.30f)<<std::endl;
	Demo((unsigned char)(10));
	add(65);
}
