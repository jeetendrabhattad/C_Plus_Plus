#include <iostream>

class Test
{
    int i = 1;
    mutable int j;// this can be changed inside constant function
    public:
    void setI() const
    {
        std::cout<<i<<std::endl;
        //const cast removes constantness
        //i = 100; i is const because of const method
        *(const_cast<int*>(&i)) = 100;
        std::cout<<"Const Cast allowed change:"<<i<<std::endl;
    }
};
int main()
{
    Test t;
    //t.setI();

    const int k = 10;
    *(const_cast<int*>(&k)) = 100;
    std::cout<<k<<":"<<*(&k)<<std::endl;
    // output 10 10 :compiler performs optimization because k is const which results into replacing value of k at places where it has been used.
    std::cout<<*(static_cast<volatile const int*>(&k))<<std::endl;
    // output 100: by using volatile we are ensuring that compiler doesn't perform optimization of replacing k's value instead it results into reading the memory of k at runtime.
}
