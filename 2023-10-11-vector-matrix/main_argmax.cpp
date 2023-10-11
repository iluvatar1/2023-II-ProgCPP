#include <iostream>
#include <random> // numeros aleatorios
#include "vector_utils.h"

int main(int argc, char **argv)
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);

  // init data
  int N = std::stoi(argv[1]);
  std::vector<double> x(N);
  // random numbers
  std::mt19937 gen(0);
  std::uniform_real_distribution<double> dis(1.0, 2.0);
  for (auto & val: x) {
    val = dis(gen);
  }

  // process data
  int idxmax = argmax(x);
  std::cout << idxmax << "\t" << x[idxmax] << "\n";
  
  return 0;
}
