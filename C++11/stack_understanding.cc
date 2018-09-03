// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
  mystack.pop();
  mystack.pop();
  //mystack.pop();
  //mystack.pop();  
//  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}
