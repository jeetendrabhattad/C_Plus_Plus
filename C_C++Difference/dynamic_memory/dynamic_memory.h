#ifndef _DYNAMIC_MEMORY_H
#define _DYNAMIC_MEMORY_H

// struct and class keyword can be used interchangeably in C++
// The only difference between C++ struct & C++ class is
// C++ class :- default access specifier is private
// C++ struct :- default access specifier is public
// You can have struct-class inheritance, class-struct inheritance
// i.e everything that we can do in C++ class can be done in C++ struct.
struct DynamicMemoryDemo
{
	// members & functions written in public access specifier can be accessed
	// from outside world using object 
	public:
	// function having same name as class name & no return value is known as Constructor.
	DynamicMemoryDemo();
	// function having same name as class name with '~' as prefix is known as Destructor.
	~DynamicMemoryDemo();
	private:
	int *m_iPtr;
	int **m_i2DArray;
};

#endif
