#include <iostream>
#include "union.h"
#include <cassert>

#define ARRAY_SIZE 10

int main() {
  int source[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "===============Testing QuickUnion class=================" << std::endl;
  std::cout << "\tTest 1:\tArray Constructor" << std::endl;
  BR::QuickUnion test1((BR::QuickUnion::size_type*) source, (BR::QuickUnion::size_type) ARRAY_SIZE);

  assert(test1.entries.size() == ARRAY_SIZE);
  std::cout << ".";

  for(BR::QuickUnion::size_type idx = 0; idx < (BR::QuickUnion::size_type) ARRAY_SIZE; ++idx) {
    assert(test1.entries.at(idx) == source[idx]);
    std::cout << ".";
  }
  
  std::cout << std::endl;

  std::cout << "\t\t\tResult - " << test1 << std::endl; 

  std::cout << "\tTest 2:\tZero Array Constructor" << std::endl;

  BR::QuickUnion test2((BR::QuickUnion::size_type*) source, 0);

  assert(test2.entries.size() == 0);
  std::cout << ".";

  return 0;
}
