#include <iostream>
//in C++ main must return int
main()
{
	int i;
	// cout:-
/*
		1) Object of ostream class.
		2) Use to insert stream of bytes on console.
		3) It is type safe. No need to specify format specifiers.
		4) It is defined in std namespace.*/
	std::cout<<"Hello World"<<std::endl; // insertion operator
		// std::cout.operator<<("Hello World");
		//	std::cout.operator<<(std::endl);
	//  cin:-
/*		1) Object of istream class.
		2) Use to extract stream of bytes from console.
		3) It is type safe, no need to speficy the format specifier.
		4) It is defined in std namespace*/
	std::cin>>i; // extraction operator
	std::cout<<i<<" is accepted\n";	
	return 1;
}
