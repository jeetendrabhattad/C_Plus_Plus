#include <iostream>

int i = 10;

namespace Test
{
    int i = 1000;
}
namespace
{
    int l = 1000;
}

int l =1;

int main()
{
    int i = 100;
    std::cout<<::i<<i<<Test::i<<::l<<std::endl;
    return 0;
}

