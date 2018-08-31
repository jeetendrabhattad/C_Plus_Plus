#include <iostream>
class Test
{
	int x;
	int y;
	int z;
	public:
	Test(int a, int b): z(a), y(b), x(z)
	{
		//garbage:20:10
		std::cout<<x<<":"<<y<<":"<<z<<std::endl;
	}
};
int main()
{
	Test t(10, 20);
}
