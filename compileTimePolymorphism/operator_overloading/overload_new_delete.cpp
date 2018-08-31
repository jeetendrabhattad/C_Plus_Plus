#include <iostream>
#include <new>
#include <stdlib.h>

void* operator new(size_t num)
{
    std::cout<<"Overloaded New "<<num<<"\n";
    return malloc(num);
}

void* operator new[](size_t num)
{
    std::cout<<"Array Creation Overloaded New "<<num<<std::endl;
    return malloc(num);
}

void operator delete(void *ptr)
{
    std::cout<<"Overloaded Delete\n";
    free(ptr);
}

void operator delete[](void *ptr)
{
    std::cout<<"Array Overloaded Delete\n";
    free(ptr);
}
    //char *p = new('*') char;
void* operator new(size_t num, char x)
{
    void *ptr;
    std::cout<<"Placement new \n";
    if (ptr = malloc(num))
		*(char*)ptr = x;
    return ptr;
}


class Test
{
	int a;
	int b;
	public:
	Test()
	{
		std::cout<<"Constructor\n";
	}
	~Test()
	{
		std::cout<<"Destructor\n";
	}
};
//  A better example of placement new
char memory[sizeof(Test)*5];
void MemoryManagement()
{
  void* p = memory;
  Test* f = new(p) Test();
  std::cout<<&memory<<":"<<f<<std::endl;
  Test* s = new((char*)p+sizeof(Test)) Test();
  std::cout<<&memory<<":"<<s<<std::endl;
  f->~Test();   // Explicitly call the destructor for the placed object
  s->~Test();   // Explicitly call the destructor for the placed object
}
int main()
{
#if 0
	// overloaded new for allocating array
	int* ptr = new int[10];
	// overloaded delete for array
	delete[] ptr;
	// overloaded new
	int* s = new int;
	// overloaded delete
	delete s;
#endif
	// initializing memory when it's allocated (placing default value while allocation)
    char *p = new('*') char;
	std::cout<<*p<<std::endl;
	delete p;
	// Managing memory allocation-deallocation from static memory.
	MemoryManagement();
}

