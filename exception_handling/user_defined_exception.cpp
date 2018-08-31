#include <iostream>
#include <exception>
#include <string>

using namespace std;

class RollNoOutOfIndex : exception
{
    int rollNo;
	public:
    RollNoOutOfIndex(int r) : rollNo(r)
    {}
	const char* what() const throw()
	{
		std::string result = "RollNo Out of Range "+std::to_string(rollNo) ;
        return result.c_str();
	}
};

int main()
{
	int rollNo;
    using namespace std;
	cout<<"Enter Roll Number:\n";
	try
	{
		cin>>rollNo;
		if(rollNo > 500)
		{
			RollNoOutOfIndex r(rollNo);
			throw r;
		}
		cout<<rollNo<<endl;
	}
	catch(RollNoOutOfIndex &e)
	{
		cout<<e.what();
	}
}

#if 0

try
{
	try{
	
	}
	catch(){
	
	}
}
catch()
{

}
#endif
