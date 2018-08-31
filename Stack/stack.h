#ifndef STACK_H_ // header-footer guards
#define STACK_H_
#include <iostream>

class Stack
{
	private:
	int *m_ipStack;
	int m_iTop;
	const int m_iSize;
	public:
	Stack(int size = 10); // constructor, with default argument
	~Stack(); //destructor, destructor never takes any parameter. Destructors cannot be overloaded.
	void push(const int data); // mutator method i.e setter method
//	void operator+(const int data);
	int pop(); // 
//	int operator-();
	int peep() const; // accessor
	bool isFull() const; // accessor
	bool isEmpty() const; // accessor
};
#endif
