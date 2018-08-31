#include "vector.h"

int main()
{
	Vector v1;
	v1.SetValue(10);
	v1.SetValue(12);
	v1.SetValue(3);
	std::cout<<v1.GetValue(0)<<":"<<v1.GetValue(1)<<":"<<v1.GetValue(2)<<std::endl;
	Vector v2;
	v2.SetValue(5);
	v2.SetValue(11);
	v2.SetValue(10);
	v2.SetValue(15);
	Vector v3 = Union(v1, v2);
	v3.Display();
	Vector v4 = Intersect(v1, v3);
	v4.Display();
	return 0;
}
