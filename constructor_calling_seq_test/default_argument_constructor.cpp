#include <iostream>

class DACT{
    public:
    DACT(int i=10, int j=20) : a(i), b(j)
    {}
    DACT(){} // this will result into ambiguity as above constructor takes 2 arguments but both has default values
    // hence when we create object like DACT t1 there will be 2 options to construct it.
    private:
    int a;
    int b;
};

/*
    int add(int a = 10, int b = 20)
    {
        return a + b;
    }
    add();
    add(10);
    add(10, 20);
*/
main()
{
    DACT t1(1,2);
    DACT t2;
    DACT t3(1);
    return 0;
}
