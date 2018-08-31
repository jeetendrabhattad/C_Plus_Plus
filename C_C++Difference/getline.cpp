#include <iostream>
using namespace std;
main()
{
	int i = 10;
	std::cout<<"Hello\n"<<i;
	char buf[10];
	cin.getline(buf, 10);
	
//	getline(buf, 10, stdin);

	std::cout<<"Buffer is "<< buf<<std::endl;
}
