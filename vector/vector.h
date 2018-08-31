#include <iostream>

class Vector{
	int *array;
	int max_size;
	int actual_size;
	public:
	Vector(int size = 10);
	Vector(const Vector&);
	~Vector();
	void Display();
	int GetValue(int index);
	int SetValue(int value);
	bool IsPresent(int value);
	friend Vector Union(Vector &v1, Vector &v2);
	friend Vector Intersect(Vector &v1, Vector &v2);
};
