#include <iostream>
#include <random> // numeros aleatorios
#include "vector_utils.h"

int main(int argc, char **argv)
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);

  // init data
  std::vector<double> poly = {1.0, 3.0, 4.5};
  std::vector<double> deriv;
  deriv.resize(poly.size() - 1);

  // process data
  deriv_poly(poly, deriv);
  for(auto val : poly) {
    std::cout << val << "\t"; 
  }
  std::cout << "\n";
  for(auto val : deriv) {
    std::cout << val << "\t"; 
  }
  std::cout << "\n";
  
  return 0;
}
