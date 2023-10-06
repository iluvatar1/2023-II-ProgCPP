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

double gauss_5(double a, double b, fptr fun)
{
    std::vector<double> x(5); // store five points in the array
    std::vector<double> w(5); // store five weights in the array
    // initialize the data, sorted from left to right
    x[0] = -std::sqrt(5 + 2*std::sqrt(10.0/7))/3;
    x[1] = -std::sqrt(5 - 2*std::sqrt(10.0/7))/3;
    x[2] = 0.0;
    x[3] = +std::sqrt(5 - 2*std::sqrt(10.0/7))/3; 
    x[4] = +std::sqrt(5 + 2*std::sqrt(10.0/7))/3;

    /*
    for(auto val : x) {
      std::cout << val << "\n";
    }
    */
    
    w[0] = (322 - 13*std::sqrt(70))/(900.0);
    w[1] = (322 + 13*std::sqrt(70))/(900.0);
    w[2] = 128.0/225.0;
    w[3] = (322 + 13*std::sqrt(70))/(900.0);
    w[4] = (322 - 13*std::sqrt(70))/(900.0);

    /*
    for(auto val : w) {
      std::cout << val << "\n";
    }
    */

    // compute the integral
    double result = 0.0;
    for (int ii = 0; ii < 5; ++ii) {
        result += w[ii]*fun((b-a)*x[ii]/2 + (b+a)/2);
    }
    return result*(b-a)/2;
}
