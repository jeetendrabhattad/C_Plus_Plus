// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  streampos begin,end;
  ifstream myfile("example.txt", ios::binary);
  begin = myfile.tellg();
  cout<<"begin :"<<begin<<endl;
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  cout<<"end :"<<end<<endl;
  myfile.close();
  cout << "size is: " << (end-begin) << " bytes.\n";
  return 0;
}
