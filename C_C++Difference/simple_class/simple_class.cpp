#include <iostream>
#include <stdlib.h>

struct Stack
{
    int iTop;
    int iSize;
    int *STACK;

    //void Init(Stack *st, int size)
    void Init(int size)
    {
        std::cout<<"Init\n";
        iTop = -1;
        iSize = size;
        STACK = (int*)malloc(size*sizeof(int));
    }

    void DeInit()
    {
        std::cout<<"DeInit\n";
        iTop = -1;
        iSize = 0;
        free(STACK);
    }
};

class CPPStack
{
    int iTop;
    int iSize;
    int *STACK;
    public:
    CPPStack(int size)
    {
        std::cout<<"Constructor :"<<size<<std::endl;
        iTop = -1;
        iSize = size;
        STACK = (int*)malloc(size*sizeof(int));
    }

    ~CPPStack()
    {
        std::cout<<"Destructor :"<<iSize<<std::endl;
        iTop = -1;
        iSize = 0;
        free(STACK);
    }
};

int main()
{
    struct Stack c1;
    //explicit call to Init and DeInit
    c1.Init(10);//Init(&c1, 10)
    c1.DeInit();

    //constructor replaces Init and is invoked implicitly when object is created
    //destructor replaces DeInit and is invoked implicitly when object goes out of scope
    CPPStack st(10);

    //creating Object Dynamically using malloc & then invoking Init, DeInit in the end
    struct Stack *c2 = NULL;
    c2 = (struct Stack*)malloc(sizeof(struct Stack));
    (*c2).Init(10);
    //perform some operations on c2
    (*c2).DeInit();
    free(c2);

    //creating class object dynamically using malloc, constructor doesn't get executed implicitly.
    CPPStack *st1 = NULL;
    st1 = (CPPStack*)malloc(sizeof(CPPStack));
    free(st1);

    //creating class object dynamically using new ensures that Construtor is invoked implicitly.
    CPPStack *st2 = NULL;
    st2 = new CPPStack(100);
    //invoking delete on object created using new ensures that Destructor is invoked implicityly.
    delete st2;

    return 0;
}
/*
   malloc                        new
   constructor is not invoked    It invokes 
   implicitly                    implicitly

   it is a function              it is operator

   argument is number of bytes   number of elements

   Explicit Type-Casting needed  Not Needed
   It returns void*              It returns respective type

   free                          delete
   destructor is not invoked     it invokes implicitly
   implicitly                       

   free is a function            it is operator  
 */
