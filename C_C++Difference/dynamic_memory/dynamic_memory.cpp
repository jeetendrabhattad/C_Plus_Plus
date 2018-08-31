#include "dynamic_memory.h"
#include <iostream>

DynamicMemoryDemo::DynamicMemoryDemo()
{
	std::cout<<"Constructor called\n";
	// creating a single dimensional array using new
	m_iPtr = new int[100];

	// creating a 2-dimensional array using new
	m_i2DArray = new int* [5];
	for( int i = 0 ; i < 5 ; i++ )
	{
		m_i2DArray[i] = new int[10];
	}
}

DynamicMemoryDemo::~DynamicMemoryDemo()
{
	std::cout<<"Destructor called\n";
	// deleting a single dimensional array
	delete[] m_iPtr;

	// delete a 2-dimensional array
	for( int i = 0 ; i < 5 ; i++ )
	{
		delete[] m_i2DArray[i];
	}
	delete [] m_i2DArray;
}

