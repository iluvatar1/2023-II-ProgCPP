#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

double f(double x);
double forward_diff(double x, double h);
double central_diff(double x, double h);

int main(int argc, char **argv)
{
  const double h = 0.01;
  double x = 1.987;
  const double dexact = std::cos(x*x)*2*x;
  double diff_f = std::fabs(1-forward_diff(x, h)/dexact);
  double diff_c = std::fabs(1-central_diff(x, h)/dexact);

  std::cout << x << "\t" << f(x) << "\t"
	    << diff_f << "\t" << diff_c << "\t"
	    << "\n";
  
  return 0;
}

double f(double x)
{
  return std::sin(x*x);
}

double forward_diff(double x, double h)
{
  return (f(x+h) - f(x))/h;
}

double central_diff(double x, double h)
{
  return (f(x+h) - f(x-h))/(2*h);  
}
