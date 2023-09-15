#include "deriv_utils.h"

double forward_diff(double x, double h, fptr f)
{
  return (f(x+h) - f(x))/h;
}

double central_diff(double x, double h, fptr f)
{
  return (f(x+h) - f(x-h))/(2*h);  
}

double richardson(double x, double h, fptr f, int order, algptr alg)
{
  double val1 = alg(x, h, f);
  double val2 = alg(x, h/2, f);
  double aux = std::pow(2.0, order);
  return (aux*val2 - val1)/(aux-1);
}
