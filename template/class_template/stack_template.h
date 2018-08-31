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

template <typename T>
void Stack<T>::push(const T &ele)
{
	elements.push_back(ele);
}

template <typename T>
T Stack<T>::pop()
{
	if(elements.empty())
	{
		return STACK_EMPTY;
	}
	T ele = elements.back();
	elements.pop_back();
	return ele;
}

template <typename T>
T Stack<T>::peep() const
{
	if(elements.empty())
	{
		return STACK_EMPTY;
	}
	return elements.back();
}

template <typename T>
bool Stack<T>::empty() const
{
	return elements.empty();
}
