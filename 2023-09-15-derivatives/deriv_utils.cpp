#include "deriv_utils.h"

double forward_diff(double x, double h, fptr f)
{
  return (f(x+h) - f(x))/h;
}

double central_diff(double x, double h, fptr f)
{
  return (f(x+h) - f(x-h))/(2*h);  
}

double richardson_forward(double x, double h, fptr f, int order)
{
  double val1 = forward_diff(x, h, f);
  double val2 = forward_diff(x, h/2, f);
  double aux = std::pow(2.0, order);
  return (aux*val2 - val1)/(aux-1);
}

double richardson_central(double x, double h, fptr f, int order)
{
  double val1 = central_diff(x, h, f);
  double val2 = central_diff(x, h/2, f);
  double aux = std::pow(2.0, order);
  return (aux*val2 - val1)/(aux-1);
}
