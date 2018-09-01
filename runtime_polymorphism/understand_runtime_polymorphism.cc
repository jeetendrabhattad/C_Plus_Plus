#include <bits/stdc++.h>
using namespace std;

class Shape
{
    public:
    Shape(){
        cout<<"Shape Constructor\n";    
    }
    ~Shape(){
        cout<<"Shape Destructor\n";    
    }
    virtual void Draw(){
        cout<<"Shape::Draw\n";
    }
};

class Circle : Shape // if no access specifier then default to private
{
    int m_iRadius;
    public:
    Circle(int rad = 0 ) : m_iRadius(rad){
        cout<<"Circle Constructor\n";
    }
    ~Circle(){
        cout<<"Circle Destructor\n";
    }
    void Draw(){
        cout<<"Drawing Circle of Radius:"<<m_iRadius<<endl;
    }
};

class Square : public Shape // if no access specifier then default to private
{
    int m_iSide;
    public:
    Square(int side = 0 ) : m_iSide(side){
        cout<<"Square Constructor\n";
    }
    ~Square(){
        cout<<"Square Destructor\n";
    }
    void Draw(){
        cout<<"Drawing Square of Side:"<<m_iSide<<endl;
    }
};

int main()
{
    Shape sObj;
    sObj.Draw(); // Shape's Draw

    Circle cObj(5);
    cObj.Draw(); // Circle's Draw
    //cObj.Shape::Draw(); //to invoke shape's Draw method provided it is accessible to object i.e available in public acces specifier.

    Square sqObj(10);
    sqObj.Draw(); // Square's Draw
    sqObj.Shape::Draw();// Shape's Draw through Square's object as Square is Shape. Shape is inherited publicly by Square hence Draw methos is accessible to Square object.

    Shape *ptr = &sObj;// Shape pointer pointing to Shape object
    cout<<"Drawing Shape using pointer of Shape pointing to Shape"<<endl;
    ptr->Draw();// Shape's Draw

    ptr = &sqObj;// Shape pointer pointing to Square object
    cout<<"Drawing Square using pointer of Shape pointing to Square"<<endl;
    ptr->Draw();// Expected is Square's Draw as Pointer is pointing to Square's object.
    //Compiler at the time compilation checks the type of ptr and it encounters that it is of type Shape. It goes to the declaration line of Draw method present inside Shape class (if not present its an error) and checks if programmer has written virtual at the line of declaration. If virtual is not written compiler resolves the method call with base class method's address. If virtual is written then compiler writes a code which results into accessing the vtable of the class which contains addresses of all virtual methods of that class. Vtable is create per class and each object contains a pointer which points to vtable. Vtable is collection of all virtual methods of that class.

    //ptr = &cObj ; //results into an error as Shape is private base class of Circle
    return 0;
}
