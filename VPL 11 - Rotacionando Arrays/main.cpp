#include <iostream>     // std::cout, std::endl
#include <vector>       // std::vector

#include "array.hpp"

// Não modifique a main

using namespace std;

main() {
  int r;
  // valor de quanto o array deve ser rotacionado
  cin >> r;
  
  vector<int> array;
  read(array);
  
  rotate(array, r);
  print(array);
  return 0;   
}