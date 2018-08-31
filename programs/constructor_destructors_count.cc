#include <iostream>

class A
{
public:
A (int n = 0):m_n (n)
  {
		std::cout<<"constructor\n";
  }
  A (const A & a):m_n (a.m_n)
  {
    ++m_copy_ctor_calls;
  }
  ~A ()
  {
	std::cout<<"destructor\n";
    ++m_dtor_calls;
  }

private:
  int m_n;

public:
  static int m_copy_ctor_calls;
  static int m_dtor_calls;
};

int
  A::m_copy_ctor_calls = 0;
int
  A::m_dtor_calls = 0;

int
main ()
{
  A *
    p = nullptr;
  {
    const A
      a = 2;
    p = new A[3];
    p[0] = a;
  }
  p[1] = A (1);
  p[2] = 2;
  delete[]p;
  std::cout << A::m_copy_ctor_calls << A::m_dtor_calls;

  return 0;
}
