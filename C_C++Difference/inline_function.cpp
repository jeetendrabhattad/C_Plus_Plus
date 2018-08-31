#include <iostream>
// inline is a request to a compiler, to make function have benefits of Macro as well as function.
inline int add(int a, int b)
{
	return a+b;
}

main()
{
	using namespace std; 
	// using & namespace are keywords 
	// namespace is logical grouping/packaging related things
	// std is one of the namespace which has all things related to Input / Output.
	// All defintions/declarations inside namespace std are directly accessible in that scope.
	cout<<"Addition result is "<<add(10, 20)<<endl;
}
