#include <iostream>

class Base 
{
	private:
	int a;
	int iBMW;
	int b;
	void BasePrivate(){}
	protected:
	int iSkoda;
	int iBaseProtected;
	void BaseProtected(){}
	public:
	int iMaruti;
	int iBasePublic;
	void BasePublic(){}
	Base() : a(0), b(0){
		std::cout<<"Base Constructor\n";
	}
	Base(int i, int j) : a(i), b(j){
		std::cout<<"Base Parametrized Constructor\n";
	}
	void Display(){
		std::cout<<"Base:"<<a<<":"<<b<<std::endl;
	}
	~Base(){
		std::cout<<"Base Destructor\n";
	}
};

class Derived : protected Base
// if inheritance is protected:- whatever is public in Base becomes protected in Derived, whatever is protected in Base remains protected in Derived, whatever is private in Base remains not accessible in Derived
{
	int c;
	int d;
	protected:
	int iDerivedProtected;
	public:
	int iDerivedPublic;
	Derived(): Base(0,0), c(0), d(0){
		std::cout<<"Derived Constructor\n";
	}
	Derived(int i, int j) : Base(i, j), c(i), d(j){
		std::cout<<"Derived Parametrized Constructor\n";
	}
	~Derived(){
		std::cout<<"Derived Destructor\n";
	}
	void Display(){
		std::cout<<"Derived:-"<<c<<":"<<d<<std::endl;
		std::cout<<"TEST Base: "<<":"<<iSkoda<<":"<<iMaruti<<std::endl;
	}
};

class Test : public Derived
{
	public:
	void Display()
	{
		std::cout<<"TEST Base: "<<":"<<iSkoda<<":"<<iMaruti<<std::endl;
		//BasePrivate();
		BasePublic();
		BaseProtected();
	}
};
main()
{
	Derived d(10, 20);
	d.Display();
 	// as methods also become protected, cannot be called using object
	//d.Base::Display();
	//d.iMaruti = d.iDerivedPublic = 20;
	Base b;
	b.Display();
	std::cout<<"Size of Base object is :-"<<sizeof(Base)<<std::endl;
	std::cout<<"Size of Derived object is:-"<<sizeof(d)<<std::endl;
}
