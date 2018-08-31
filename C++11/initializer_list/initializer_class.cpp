#include <iostream>
#include <initializer_list>
#include <vector>

class TestInitializer
{
    std::vector<int> test;// 3rd choice provided it is made public
    public:
    //Compiler gives first priority to initializer list constructor : 1st choice
    TestInitializer(const std::initializer_list<int>& v){
        std::cout<<"TestIntializer"<<std::endl;
        for(auto it = v.begin() ; it != v.end() ; it++)
            test.push_back(*it);
    }
    //Compiler gives second priority to parameterized constructor : 2nd choice
    TestInitializer(int a)
    {
        std::cout<<"Explicit int argument."<<std::endl;
        test.push_back(a);
    }
    //if none of the above is present the Compiler tries to perform aggregate intialization
};

class AggregateInitialization
{
    public:
    int i;
};

int main()
{
    //both are same
    TestInitializer t = {1,2,3};
    TestInitializer t1{1,2,3};
    //this results into invoking initializer list constructor, if that is not found then it goest to pararmetrized constructor
    TestInitializer t3{1};
    //this is explicit call to parameterized constructor
    TestInitializer t2(1);
    
    //as the class doesn't contain constructor with initializer list nor with parameterized compiler tries to perform sequential intialization to variables in their declaration order which is known as aggreagte initialization
    AggregateInitialization t4{4};
    return 0;
}
