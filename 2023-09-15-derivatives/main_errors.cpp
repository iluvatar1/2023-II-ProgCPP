#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "deriv_utils.h"

double fun(double x);

int main(int argc, char **argv)
{
  const double x = 1.454335;
  std::ofstream fout("datosh.txt");
  fout.precision(15);
  fout.setf(std::ios::scientific);
  for(double h = 1.0e-16; h <= 1.0e-1; h = h*10.0) {
    const double dexact = std::cos(x*x)*2*x;
    double diff_f = std::fabs(1-forward_diff(x, h, fun)/dexact);
    double diff_c = std::fabs(1-central_diff(x, h, fun)/dexact);
    fout << h << "\t" << fun(x) << "\t"
	 << diff_f << "\t" << diff_c << "\t"
	 << "\n";
  }
  fout.close();
  
  return 0;
}

double fun(double x)
{
  return std::sin(x*x);
}
