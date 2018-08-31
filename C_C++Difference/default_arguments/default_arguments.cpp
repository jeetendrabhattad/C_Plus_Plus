#include <iostream>
//they must be trailing
//int add(int a = 10, int b)
//add(10) -- here it goes to a and be remains unassigned with any value hence compiler gives an error.
int add(int a, int b = 10) //default arguments
{
    return a+b;
}

int main()
{
    add(10);
    add(20, 30);
    return 0;
}
