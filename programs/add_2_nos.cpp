#include <iostream>

// a = 17 : 10001
// b = 23 : 10111 
// a ^ b : 000110
// carry : 100010

//a : 6 : 000110
//b : 34 :100010
//a ^ b  :100100 
//carry : 
//      a&b:000010
//      <<1:000100

//a : 36 : 100100
//b : 4 :  000100
//a ^ b:   100000
//carry :  001000

//a : 32 : 100000
//b : 8  : 001000
//a ^ b :  101000
//carry :  000000

//a : 40
//b : 0
int add(int a, int b)
{
	if (b == 0) return a;
	int sum = a^b;
	//std::cout<<sum<<std::endl;
	int carry = (a&b)<<1;
	return add(sum, carry);
}

int sub(int a, int b)
{
	return add(a, add(~b, 1));
}
int main()
{
	std::cout<<add(10, 12)<<std::endl;
	std::cout<<sub(15, 12)<<std::endl;
	std::cout<<sub(25, 12)<<std::endl;
}
