// deque::emplace_from
#include <iostream>
#include <deque>
#include <list>

int main ()
{
  std::deque<int> mydeque = {10,20,30};
  std::list<int> l1 = {1,2,3,4,5};
  mydeque.emplace_back (l1.front());
  mydeque.emplace_back (200);

  std::cout << "mydeque contains:";
  for (auto& x: mydeque)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
