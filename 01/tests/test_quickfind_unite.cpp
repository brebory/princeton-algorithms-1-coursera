#include <iostream>
#include "union.h"
#include <cassert>

#define ARRAY_SIZE 10

int main() {
  int source[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\tTest 3:\tUnite Method" << std::endl;

  BR::QuickFind test1((BR::QuickFind::size_type*) source, (BR::QuickFind::size_type) ARRAY_SIZE);

  test1.unite(1, 2);

  assert(test1.entries.at(1) == test1.entries.at(2));

  std::cout << ".";

  test1.unite(3, 4);

  assert(test1.entries.at(3) == test1.entries.at(4));

  std::cout << ".";

  test1.unite(1, 4);

  assert(test1.entries.at(1) == test1.entries.at(4));

  std::cout << ".";

  assert(test1.entries.at(2) == test1.entries.at(3));

  std::cout << ".";

  std::cout << std::endl;

  std::cout << "\t\t\tResult - " << test1 << std::endl;

}
