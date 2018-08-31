#include <iostream>
#include "dynamic_memory.h"
#include <stdlib.h>

// main must return int in C++.
int main()
{
	// creating object of DynamicMemoryDemo on stack
	// on elaboration time of function constructor for S1 is invoked.
	// after control reaches out of function destructor will be invoked.
	DynamicMemoryDemo S1;
	
	// creating object using malloc on heap.
	// malloc will not result into invoking constructor implicitly.
	// malloc return value must be type-casted to respective type.
	DynamicMemoryDemo *smalloc = (DynamicMemoryDemo*)(malloc(sizeof(DynamicMemoryDemo)));
	// free will free the memory allocated to object on heap
	// free will not result into invoking destructor implicitly.
	free(smalloc);

	// creating object using new operator on heap.
	// new returns the address of respective type hence no type-casting required.
	// using new results into invoking constructor implicitly.
	DynamicMemoryDemo *snew = new DynamicMemoryDemo;
	// frees object created on heap
	// delete will call destructor implicitly

	// Note: Always use malloc/calloc/realloc & free combination
	// or new & delete combination.
	// Never inter-mix them result will be undefined.
	delete snew;
    std::cout<<"At End of Main\n";
	return 0;
}
