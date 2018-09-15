#include <iostream>
#include <cstring>
using namespace std;

class CString
{
    char *m_data = NULL;//intialization at declaration line
    int m_size = 10;
    public:
    CString()
    {
        cout<<"Default Constructor\n";
        m_data = new char[m_size];
        strcpy(m_data, "Jeetendra");
        //init(10, "Jeetendra");
    }
    CString(int size, const char *name)
    {
        //init(size, name);
        cout<<"Parametrized Constructor\n";
        m_size = size;
        m_data = new char[size];
        strcpy(m_data, name);
    }
    CString(std::string name) 
    : CString(name.size(), name.c_str()) //delegating constructor
    {
        cout<<"std::string Constructor\n";
        //init(name.size(), name.str());
    }
    //to perform deep copy : copy constructor is must
    CString(const CString& obj) : CString(obj.m_size, obj.m_data)
    {
        cout<<"Copy Constructor\n";
    }
    CString& operator=(const CString &obj)
    {
        if(this == &obj)
        {
            cout<<"Self assignment, nothing needs to be done.\n";
        }
        else
        {
            cout<<"Deep Copy via Assignment Operator\n";
            if(this->m_data)
                delete[] this->m_data;
            this->m_size = obj.m_size;
            this->m_data = new char[m_size];
            strcpy(m_data, obj.m_data);
        }
        return *this;
    }
    char* getData() const
    {
        return m_data;
    }
    ~CString()
    {
        cout<<"Destructor "<<m_data<<endl;
        delete[] m_data;
        //m_data = NULL;
    }
};
int main()
{
    CString s1;
    CString s2(6, "hello");
    CString s3(std::string("Cool"));

    cout<<s1.getData()<<endl;
    cout<<s2.getData()<<endl;
    cout<<s3.getData()<<endl;

    CString s4(s3);//copy constructor

    s2 = s4;
    s2 = s2;
    CString s5(CString(6, "Morya"));
    // x(6, "Morya"), s5(x)
    return 0;
}
