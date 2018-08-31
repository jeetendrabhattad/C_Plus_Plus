#include <iostream>

void SwapByCPPReference(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void DemoReferenceVariable()
{
	int no1 = 10, no2 = 50;
	std::cout<<"Before swap no1 is "<<no1<<" no2 is "<<no2<<std::endl;
	SwapByCPPReference(no1, no2);
	std::cout<<"After swap no1 is "<<no1<<" no2 is"<<no2<<std::endl;

	int &refNo1 = no1; // reference must be initialized
	std::cout<<"Using refernce no1 is "<<refNo1<<std::endl;

	refNo1 = no2; // once initialized cannot be intialized to anyother variable
	std::cout<<" no1 is "<<no1<<std::endl;

	const int &refToConst = no1;
	//refToConst = 20;
	no1 = 40;
	// you cannot create reference to a reference and if you try to do so it will be created the original variable to which the existing reference is referring.
	int &referenceToRefNo1 = refNo1;
    //int &refC = 10
	const int &refConst = 10;
    static int &staticRef = refNo1;
    int *ptr = &no1;
    int* &refPtr = ptr;
    std::cout<<&refPtr<<":"<<&ptr<<std::endl;
    *refPtr = 200;
    std::cout<<*refPtr<<":"<<*ptr<<std::endl;
}

int main()
{
	DemoReferenceVariable();
}
