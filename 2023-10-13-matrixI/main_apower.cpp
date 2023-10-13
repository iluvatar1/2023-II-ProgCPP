#include <iostream>
#include <vector>
#include <string>
#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int P = std::stoi(argv[2]);

  std::vector<double> array2d(M*M, 0.0);
  std::vector<double> result(M*M, 0.0);
  fill_matrix(array2d, M, M);

  power(array2d, M, P, result);
  
  print_matrix(array2d, M, M);
  print_matrix(result, M, M);

  return 0;
}
