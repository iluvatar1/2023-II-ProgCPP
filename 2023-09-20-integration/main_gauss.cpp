#include <iostream>
#include "integration.h"

double fun(double x);
double bar(double x);

int main(int argc, char **argv)
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  
  //std::cout << trapezoid(0.0, 1.0, 10, fun) << "\n";
  //std::cout << trapezoid(0.0, 1.0, 1000, fun) << "\n";
  //std::cout << trapezoid(0.0, 1.0, 10000000, fun) << "\n";
  //std::cout << gauss_5(0.0, 1.0, fun) << "\n";

  std::cout << trapezoid(0.0, 0.5, 10, bar) << "\n";
  std::cout << trapezoid(0.0, 0.5, 1000, bar) << "\n";
  std::cout << trapezoid(0.0, 0.5, 10000000, bar) << "\n";
  std::cout << gauss_5(0.0, 0.5, bar) << "\n";
  std::cout << std::erf(0.5) << "\n";
  
  return 0;
}

double fun(double x)
{
  return x*x;
}

double bar(double x)
{
  return std::exp(-x*x)*2/std::sqrt(M_PI);
}
