#ifndef UNION_H
#define UNION_H

class Sample
{

};

union SampleUnion 
#ifdef UNIONINHERITANCE
: public Sample
#endif
{
	private:
	short int m_iNumber;
	char m_cData[2];
//	static int m_iStatic;
//	int &m_iReference;
	public:
	SampleUnion();
	~SampleUnion();
	int GetNumber() const;
	void SetNumber(int number);
	
};

#ifdef UNIONBASE
class UnionBase : public SampleUnion
{

};
#endif

#if 0
// Not allowed operations on Union
i) union cannot inherit any other classes of any type.
ii) union cannot be a base class.
iii) union cannot have virtual function.
iv) Static variables cannot be part of union.
v) union cannot have a reference member.
vi) union cannot have an object of class that overloads "=" operator.
vii) No object can be member of a union if that object has an explicit constructor/destructor function.
#endif

#endif
