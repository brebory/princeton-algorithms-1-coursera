#include <iostream>
#include "union.h"
#include <cassert>

#define ARRAY_SIZE 10

int main() {
  int source[ARRAY_SIZE] = {1, 2, 3, 3, 4, 5, 5, 5, 6, 6};

  std::cout << "\tTest 2:\tfind method" << std::endl;

  BR::QuickFind test1((BR::QuickFind::size_type*) source, (BR::QuickFind::size_type) ARRAY_SIZE);
  
  assert(test1.find(1, 3) == false);
  std::cout << ".";
  assert(test1.find(5, 6) == true);
  std::cout << ".";

  std::cout << std::endl;

  return 0;

}
