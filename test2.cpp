#include <iostream>
#include <cstdint>

int main()
{
  std::string msg{"Hello, World!"};
  std::cout << msg << std::endl;
  if(5 > 6){std::cout << "Wrong Message";}else{std::cout << "Nothing";}
  return 0;
}
