/*
  for each loop can be used on all classes which provide begin and end method
*/

#include <iostream>
#include <vector>
#include <initializer_list>

class ForEachClass
{
    std::vector<int> test;
    public:
    ForEachClass(const std::initializer_list<int>& i)
    {
       for(int j : i)
          test.push_back(j);
    }

    auto begin()
    {
        return test.begin();
    }

    auto end()
    {
        return test.end();
    }
};

int main()
{
    std::vector<int> test = {1,2,3,4,5};
    ForEachClass test_obj = {1,3,5,7,9};
    //for(auto it : test)
    for(int it : test)
        std::cout<<"for each iterator: "<<it<<std::endl; // it is of type integer only
    //iterates the object as it provides the begin and end method	
    for(int it : test_obj)
        std::cout<<"for each user defined class iterator: "<<it<<std::endl; // it is of type integer only
    return 0;
}
