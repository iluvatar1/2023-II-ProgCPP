#include <iostream>
#include <random> // numeros aleatorios
#include "vector_utils.h"

int main(int argc, char **argv)
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);

  // init data
  std::vector<double> poly = {1.0, 3.0, 4.5};

  
  // process data
  double x = 1.0;
  double valp = eval_poly(poly, x);
  double valpderiv = eval_poly_deriv(poly, x);

  std::cout << valp << "\n";
  std::cout << valpderiv << "\n";
  
  return 0;
}
// p(x) = 1 + x^10000 -> Cual tamanho debe tener el vector? 10001
// 1) vector
// 2) map
