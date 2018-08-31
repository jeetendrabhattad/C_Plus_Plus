#include <iostream>

template <typename T>
T add(T a, T b = 1)
{
	return a+b;
}
/*
class Test
{};
T3 = T1 + T2; //T3.operator=(T1.operator+(T2))*/
template <typename T>
T add(T a, T b, T c)
{
	return a+b+c;
}

template <class RT, class T1, typename T2>
RT add(T1 a, T2 b)
{
	std::cout<<__FUNCTION__<<":"<<__LINE__<<std::endl;
	return a+b;
}
#if 0
//template specialization
int add(int a, int b)
{
	std::cout<<" Specialization Integer Addition "<<__FUNCTION__<<std::endl;
	return a+b;
}
#endif
int main()
{
	std::cout<<"Addition of integer:-"<<add(10,20)<<std::endl;
	std::cout<<"Addition of integer overloaded function:-"<<add(10,20,30)<<std::endl;
	std::cout<<"Addition of double:-"<<add(10.20,20.30)<<std::endl;
	std::cout<<"Addition of double overloaded function:-"<<add(10.20,20.30, 31.30)<<std::endl;
	std::cout<<"Addition of int-double:-"<<add<float>(20.30, 10)<<std::endl;
	std::cout<<"Addition of int-double:-"<<add<int>(20.30, 10)<<std::endl;
}
