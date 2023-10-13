#include <iostream>
#include <vector>
#include <string>
#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> array2d(M*N, 0.0);
  std::vector<double> array2d_T(N*M, 0.0);
  std::vector<double> result(M*M, 0.0);
  fill_matrix(array2d, M, N);

  transpose_matrix(array2d, M, N, array2d_T);
  matmul(array2d, M, N, array2d_T, N, M, result);
  
  print_matrix(array2d, M, N);
  print_matrix(array2d_T, N, M);
  print_matrix(result, M, M);

  return 0;
}
