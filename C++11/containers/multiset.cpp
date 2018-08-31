// multiset::begin/end
#include <iostream>
#include <set>

int main ()
{
  int myints[] = {42,71,71,71,12};
  std::set<int> mymultiset (myints,myints+5);


  std::cout << "mymultiset contains:";
  for (std::set<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
  {  std::cout << ' ' << *it;
  }

  std::cout << '\n';

  return 0;
}
