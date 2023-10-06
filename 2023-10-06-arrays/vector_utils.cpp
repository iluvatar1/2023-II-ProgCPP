#include "vector_utils.h"

double pnorm(const std::vector<double> & data, int p)
{
  double suma = 0.0;
  // accumulate
  for (auto val : data) {
    suma += std::pow(val, p);
  }
  return std::pow(suma, 1.0/p);
}
