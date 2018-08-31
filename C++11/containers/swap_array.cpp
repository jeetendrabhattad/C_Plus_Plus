// swap arrays
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> first = {10, 20, 30, 40, 50};
  std::array<int,5> second = {11, 22, 33, 44, 55};

  first.swap (second);

  std::cout << "first:";
  for (int& x : first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second:";
  for (int& x : second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
