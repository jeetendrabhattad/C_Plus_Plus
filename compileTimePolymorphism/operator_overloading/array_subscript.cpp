#include <iostream>

class ArraySubscriptOverload
{
	int *array;
	int n;
	public:
	ArraySubscriptOverload(int x = 10) : n(x)
	{
		array = new int[n];
	}
	
	~ArraySubscriptOverload()
	{
		delete[] array;
	}
	void AcceptArray()
	{
		std::cout<<"Enter "<<n<<" values:-";
		for(int i = 0 ; i < n ; i++)
			std::cin>>array[i];
	}
		
	int operator[](int index)
	{
		if(index < n)
			return array[index];
		return -1;
	}
		
};

int main()
{
	ArraySubscriptOverload obj;
	obj.AcceptArray();
	std::cout<<obj[4]<<std::endl;
	std::cout<<"calling overloaded function explicitly:-"<<obj.operator[](6)<<std::endl;
}







