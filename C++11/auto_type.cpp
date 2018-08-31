/*
   auto typing : auto a = 6; a becomes an integer
                 auto b = a; b becomes an integer as a is also an integer
   Advantage : Have to type less
   Drawback : if the program grows one might have to debug and find out what is the type of variable 
*/

#include <iostream>
#include <vector>
int main()
{
    auto i = 100;
    auto j = i;

    std::vector<int> v = {1,3,4,4,5};

    for(std::vector<int>::iterator it1 = v.begin() ; it1 != v.end() ; it1++)
        std::cout<<"Explicit Iterator : *it="<<*it1<<std::endl;
 
    for(auto it = v.begin() ; it != v.end() ; it++)
        std::cout<<"Auto Iterator*it="<<*it<<std::endl;
    return 0;
}
