#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "deriv_utils.h"

double fun(double x);

int main(int argc, char **argv)
{
  const double x = 1.454335;
  std::ofstream fout("datos-r.txt");
  fout.precision(15);
  fout.setf(std::ios::scientific);
  for(double h = 1.0e-16; h <= 1.0e-1; h = h*10.0) {
    const double dexact = std::cos(x*x)*2*x;
    double diff_f = std::fabs(1-forward_diff(x, h, fun)/dexact);
    double diff_c = std::fabs(1-central_diff(x, h, fun)/dexact);
    double diff_rf = std::fabs(1-richardson_forward(x, h, fun, 1)/dexact);
    double diff_rc = std::fabs(1-richardson_central(x, h, fun, 2)/dexact);
    fout << h << "\t" << fun(x) << "\t"
	 << diff_f << "\t" << diff_c << "\t"
	 << diff_rf << "\t" << diff_rc << "\t"
	 << "\n";
  }
  fout.close();
  
  return 0;
}

double fun(double x)
{
  return std::sin(x*x);
}
