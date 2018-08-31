#include <iostream>

class B
{
public:
  virtual int shift (int n = 2) const
  {
    std::cout<<"Called this\n";
    return n << 2;
  }
};

class D:public B
{
public:
  int shift (int n = 3) const
  {
	std::cout<<"value of n is "<<n<<std::endl;
    return n << 3;
  }
};

int
main ()
{
  const D d;
  const B *b = &d;

  std::cout << b->shift () << std::endl;

  return 0;
}
