#include <iostream>

class A
{
public:
  A (int i):m_i (i)
  {
		  std::cout<<"const\n";
  }

public:
  int operator () (int i = 0) const
  {
    return m_i + i;
  }

  operator  int () const
  {
    return m_i;
  }

private:
  int m_i;

  friend int g (const A &);
};

int
f (char c)
{
  return c;
}

int
g (const A & a)
{
  std::cout<<"G invoked\n";
  return a.m_i;
}

int
main ()
{
  A f (2);
  A g (3);
  ::g(f);
  std::cout << f (1) << g (f) << std::endl;

  return 0;
}
