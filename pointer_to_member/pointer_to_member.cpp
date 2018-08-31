#include <iostream>

class PointerToMember
{
	public:
	int val;

	PointerToMember(int i) : val(i)
	{
		std::cout<<"Constructor\n";
	}
	~PointerToMember()
	{
		std::cout<<"Destructor\n";
	}
};
int main()
{
	PointerToMember obj(10), obj2(20);
	int *ptr;
	ptr = &obj.val;
	*ptr = 300;
	ptr = &obj2.val;
	*ptr = 400;

	std::cout<<"\n Value of val:-"<<obj.val<<std::endl;
	//declaration
	int PointerToMember::*data = &PointerToMember::val;		
	obj.*data = 2000;
	std::cout<<"\n Value of val:-"<<obj.val<<std::endl;
	obj2.*data = 100;
	std::cout<<"\n Value of val:-"<<obj2.val<<obj2.*data<<std::endl;
}
