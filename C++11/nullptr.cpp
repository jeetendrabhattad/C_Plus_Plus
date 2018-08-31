#include <iostream>

void bar(int i)
{
    std::cout<<"Bar Invoked with :"<<i<<std::endl;
}
void bar(char* i)
{
    std::cout<<"Bar nullptr Invoked with :"<<i<<std::endl;
}
int main()
{
    //bar(NULL); // results into an ambiguity as NULL is defined as 0 hence the bar with int argument and with char* both are valid option

    bar(nullptr);
    return 0;
}
