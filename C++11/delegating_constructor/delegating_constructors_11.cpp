#include <iostream>
#include <string.h>

class CString
{
    private:
    char* m_string;
    int m_size = 10; //for all objects value will be 10 if not updated
    public:
    CString(int size = 10)
    {
        m_string = new char[size+1];
        m_size = size;
    }
    //delegation constructor, constructor of same class must be invoked on initialization list
    CString(char *str) : CString(strlen(str))
    {
        //copy string
        strcpy(m_string, str);
    }
    const char* getString() const
    {
        return m_string;
    }
};

int main()
{
    //In above class if we observer carefully the Init method is added as both the ways of creating CString needs default initialization of memory creation and intializing size variable.
    //In C++03 - we cannot add the code present in init in default constructor and then invoke the default constructor explicitly from other 2.
    //In C++03 - invoking constructor from constructor results into creating a new object

    //The drawback of providing an init method is it can be invoked by any other function which will result into undesirable behavior.

    //To overcome above drawback C++11 supports invoking other constructor from a constructor and results into changing the same object.
    CString jeetendra("jeetendra");
    std::cout<<"String is :"<<jeetendra.getString()<<std::endl;
    return 0;
}
