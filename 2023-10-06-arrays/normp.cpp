#include <iostream>
#include <random> // numeros aleatorios
#include "vector_utils.h"

int main(int argc, char **argv)
{
  // init data
  //std::vector<double> x{1.0, 1.0, 1.0, 1.0};
  int N = 4000;
  std::vector<double> x(N);
  // random numbers
  std::mt19937 gen(0);
  std::uniform_real_distribution<double> dis(1.0, 2.0);
  for (auto & val: x) {
    val = dis(gen);
  }
  //for (auto val: x) {
  //  std::cout << val << " ";
  // }
  //std::cout << "\n";

  // process data
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  for(int p = 1; p <= 20; p++) {
    std::cout << p << "\t" << pnorm(x, p) << "\n";
  }
  
  return 0;
}
