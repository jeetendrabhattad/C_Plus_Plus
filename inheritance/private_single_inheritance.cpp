#include <iostream>

class Base 
{
	private:
	int iBMW;
	void BasePrivate(){}
	protected:
	int iSkoda;
	void BaseProtected(){}
	public:
	int iMaruti;
	void BasePublic(){}
	Base() {
		std::cout<<"Base Constructor\n";
	}
	Base(int i, int j) {
		std::cout<<"Base Parametrized Constructor\n";
	}
	virtual void Display(){
		std::cout<<"Base:"<<std::endl;
	}
	~Base(){
		std::cout<<"Base Destructor\n";
	}
};

class Derived : private Base
// if inheritance is private:- whatever is public in Base becomes private in Derived, whatever is protected in Base becomes private in Derived, whatever is private in Base remains not accessible in Derived
{
	protected:
	int iDerivedProtected;
	public:
	int iDerivedPublic;
	Derived(): Base(0,0){
		std::cout<<"Derived Constructor\n";
	}
	Derived(int i, int j) : Base(i, j){
		std::cout<<"Derived Parametrized Constructor\n";
	}
	~Derived(){
		std::cout<<"Derived Destructor\n";
	}
    private:
	void Display(){
		std::cout<<"Derived:-"<<std::endl;
		std::cout<<"TEST Base: "<<":"<<iSkoda<<":"<<iMaruti<<std::endl;
	}
};

class Test : public Derived
{
	public:
	void Display()
	{
		//std::cout<<"TEST Base: "<<":"<<iSkoda<<":"<<iMaruti<<std::endl; // as Derived is inheriting Base privately all members of Base won't be accessible in class derived from Derived
		//BasePrivate();
		//BasePublic();
		//BaseProtected();
	}
};
main()
{
	Derived d(10, 20);
	//d.Display();
 	// as methods also become protected, cannot be called using object
	//d.Base::Display();
	//d.iMaruti = d.iDerivedPublic = 20;
	Base b;
	b.Display();
	std::cout<<"Size of Base object is :-"<<sizeof(Base)<<std::endl;
	std::cout<<"Size of Derived object is:-"<<sizeof(d)<<std::endl;

	Base *obj = &d;
	obj->Display();
    obj = &b;
	obj->Display();

}
