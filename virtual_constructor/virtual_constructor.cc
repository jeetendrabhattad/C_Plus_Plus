#include <bits/stdc++.h>

using namespace std;

class Triangle
{
    protected:
    int angle_1, angle_2, angle_3;
    public:
    Triangle(int ag1 = 60, int ag2 = 60, int ag3 = 60) : angle_1(ag1), angle_2(ag2), angle_3(ag3){
        cout<<"Triangle Constructor"<<endl;
    }
    ~Triangle(){
        cout<<"Triangle Destructor"<<endl;
    }
    virtual Triangle* Clone(){
    //Triangle* Clone(){
        cout<<"Triangle Clone"<<endl;
        return new Triangle(angle_1, angle_2, angle_3);
    }
};

class RightAngledTriangle : public Triangle
{
    public:
    RightAngledTriangle(int ag1 = 90, int ag2 = 45, int ag3 = 45) : Triangle(ag1, ag2, ag3){
        cout<<"Right Angled Triangle Constructor"<<endl;
    }
    ~RightAngledTriangle(){
        cout<<"Right Angled Triangle Destructor"<<endl;
    }
    //CoVariant : C++ allows the derived type to implement an overridden function with return type that is a sub-type of the return type of the base function.
    virtual RightAngledTriangle* Clone(){  
    //RightAngledTriangle* Clone(){  
        cout<<"RightAngledTriangle Clone"<<endl;
        return new RightAngledTriangle(angle_1, angle_2, angle_3);
    }
};

void TestTriangle(Triangle *tr)
{
    Triangle *tr_clone = tr->Clone(); // creating an object through virtual method making constructor behave like a virtual constructor

    delete tr_clone;
}

int main()
{
    RightAngledTriangle rt(90, 45, 45);
    TestTriangle(&rt);
    return 0;
}

#if 0
When Clone is Not Made virtual :
Triangle Constructor
Right Angled Triangle Constructor
Triangle Clone ---> Clone of Right Angled Triangle should have been executed but as pointer type is Triangle clone of Triangle gets invoked
Triangle Constructor
Triangle Destructor
Right Angled Triangle Destructor
Triangle Destructor

When Clone is Made virtual :
Triangle Constructor
Right Angled Triangle Constructor
RightAngledTriangle Clone ---> Clone of Right Angled Triangle gets invoked as though pointer is of type Triangle but it is pointing to RightAngledTrianle object.
Triangle Constructor
Right Angled Triangle Constructor
Triangle Destructor
Right Angled Triangle Destructor
Triangle Destructor
#endif
