#include <iostream>
#include <vector>
#include <stdexcept>

typedef enum
{
	STACK_FULL = -1,
	STACK_EMPTY = 0,
}STACK_STATUS_T;

template <typename T>

class Stack{
	private:
	std::vector<T> elements;
	public:
	void push(const T &ele); // push element
	T pop(); // pop element
	T peep() const; // what's at the top
	bool empty() const;
};

