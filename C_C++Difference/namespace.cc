#include <iostream>

int i = 10;
namespace {
	int i = 30;
}

int main()
{
//	int i = 20;
//    using namespace test;	
	std::cout<<i<<":"<<::i<<":"<<::i<<std::endl;
	//std::cout<<i<<":"<<test::i<<":"<<::i<<std::endl;
	return 0;
}
