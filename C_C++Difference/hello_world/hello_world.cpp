#include <iostream>

struct Calculator
{
	int a;
	int b;
}calc;

int add( Calculator c)
{
	return c.a+c.b;
}

main()
{
	//calc function
	// calc.a & calc.b
	// add(calc)
}
//using namespace std;
//
/*
namespace std
{
	struct ostream
	{
		ostream& operator <<(void*data)
		{
			write
		}
	}cout;

	struct istream
	{	
		//methods
	}cin;
}

*/
int main()
{
	// cout is an object of ostream class, it has method with '<<' which displays output on stdout.
	std::cout<<"HELLO WORLD\n";
// :: scope resolution operator
// std - name of namespace
	return 0;
}







