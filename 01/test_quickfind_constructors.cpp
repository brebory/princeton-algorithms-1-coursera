#include <iostream>
#include "union.h"
#include <cassert>

#define ARRAY_SIZE 10

int main(int argc, char **argv) {
  int[ARRAY_SIZE] source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  std::cout << "============Testing QuickFind class==========" << std::endl;
  std::cout << "\tTest 1:\tArray Constructor" << std::endl;

  QuickFind test1((BR::size_type*) source, (BR::size_type) ARRAY_SIZE);
  
  assert(test1.entries.size() == ARRAY_SIZE);
  std::cout << ".";

  for(BR::size_type idx = 0; idx < (BR::size_type) ARRAY_SIZE; ++idx) {
    assert(test1.entries.at(idx) == array[idx]);
    std::cout << ".";
  }

  std::cout << std::endl;
    
  std::cout << "\t\t\tResult - " << test1 << std::endl;
   
}
