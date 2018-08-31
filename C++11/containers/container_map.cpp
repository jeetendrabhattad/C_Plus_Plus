/* Maps are associative containers that store elements formed by a combination of 
 * key value and a mapped value following a specific order.
 * mapped values can be directly accessed using map[key]
 */

// multimap::begin/end
#include <iostream>
#include <map>

int main ()
{
  std::multimap<char,int> mymultimap;

  mymultimap.insert (std::pair<char,int>('a',10));
  mymultimap.insert (std::pair<char,int>('b',20));
  mymultimap.insert (std::pair<char,int>('b',150));

  // show content:
  for (std::multimap<char,int>::iterator it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';
  std::cout<<mymultimap.count('b');
  return 0;
}
