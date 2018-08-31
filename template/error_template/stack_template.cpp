#include "stack_template.h"

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

