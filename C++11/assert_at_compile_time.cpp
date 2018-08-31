#include <iostream>

int main()
{
    static_assert(sizeof(int) == 4, "Failed");
    //static_assert(sizeof(int) == 1, "Failed"); //asserts as sizeof(int) is not 1
    return 0;
}
