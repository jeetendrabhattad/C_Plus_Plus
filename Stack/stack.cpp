#include "stack.h"

Stack::Stack(int size) : 
  m_iSize(size),
  m_iTop(-1) // list of initialization after : is true initialization
{
	m_ipStack = new int[m_iSize];
}

Stack::~Stack()
{
	delete[] m_ipStack;
}

void Stack::push(const int data)
{
	this->m_ipStack[++(this->m_iTop)] = data; 
}

int Stack::pop()
{
	int temp;
	temp = m_ipStack[m_iTop];
	m_iTop--;
	return temp;
}

int Stack::peep() const
{
	return m_ipStack[m_iTop];
}

bool Stack::isFull() const
{
	return m_iTop == m_iSize;
}

bool Stack::isEmpty() const
{
	return this->m_iTop == -1;
}
