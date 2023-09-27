#include "integration.h"

double trapezoid(double a, double b, int n, fptr fun)
{
  const double dx = (b-a)/n;
  double suma = 0.0;
  suma += (fun(a) + fun(b))/2;
  for(int k = 1; k <= n-1; k++) {
    double xk = a + k*dx;
    suma += fun(xk);
  }
  return suma*dx;
}
