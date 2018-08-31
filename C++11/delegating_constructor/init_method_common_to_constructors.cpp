#include <iostream>

class CString
{
    private:
    char* m_string;
    int m_size;
    void Init(int size)
    {
        m_string = new char[size+1];
        m_size = size;
    }
    public:
    CString(int size = 10)
    {
        Init(size);
    }
    CString(char *str)
    {
        Init(strlen(str));
        //copy string
    }
};

int main()
{
    //In above class if we observer carefully the Init method is added as both the ways of creating CString needs default initialization of memory creation and intializing size variable.
    //In C++03 - we cannot add the code present in init in default constructor and then invoke the default constructor explicitly from other 2.
    //In C++03 - invoking constructor from constructor results into creating a new object

    //The drawback of providing an init method is it can be invoked by any other function which will result into undesirable behavior.

    //To overcome above drawback C++11 supports invoking other constructor from a constructor and results into changing the same object.
    return 0;
}
