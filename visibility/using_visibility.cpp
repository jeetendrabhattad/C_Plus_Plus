#include <iostream>

class Base
{
	private:
		int iPrivate;
		void PrivateMethod()
		{
			std::cout<<"PrivateMethod of Base Class\n";
		}
	protected:
		int iProtected;
		void ProtectedMethod()
		{
			iProtected = 300;
			std::cout<<"ProtecteMethod of Base Class\n";
		}
	public:
		int iPublic;
		void PublicMethod()
		{
			std::cout<<"PublicMethod of Base Class";
		}
};

class Derived : private Base
{
	private:
#if PRIVATE
	//	using Base::PrivateMethod; //Not Accessible in anycase
		using Base::ProtectedMethod; //Protected to Private Visibility
		using Base::PublicMethod;//Public to Private Visibility
#endif
	public:
#if PUBLIC
		using Base::iProtected;
		using Base::PublicMethod;
	//	using Base::PrivateMethod; //Not accessible in anycase
		using Base::ProtectedMethod;
#endif
	protected:
#if PROTECTED
//		using Base::PrivateMethod; //Not accessible in anycase
		using Base::iPublic;
		using Base::PublicMethod;
#endif
};

int main()
{
#if PUBLIC
	Derived obj;
	obj.ProtectedMethod();
	std::cout<<"Protected of Base made public in Derived "<<obj.iProtected<<std::endl;
#endif
}
