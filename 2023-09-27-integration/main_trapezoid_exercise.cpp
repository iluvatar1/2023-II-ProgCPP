#include <iostream>
#include <cmath>
#include <fstream>
#include "integration.h"

double fun(double x);

int main(int argc, char **argv)
{
  std::ofstream fout;
  fout.open("erf_data.txt");
  
  fout.precision(15);
  fout.setf(std::ios::scientific);

  for(double b = 0.1; b <= 10.0; b += 0.1) {
    double exact = std::erf(b);
    double numerical = trapezoid(0.0, b, 100, fun);
    double error = std::fabs(1.0 - numerical/exact);
    fout << b << "\t" 
	 << numerical << "\t"
	 << error << "\n";
  }

  fout.close();
  
  return 0;
}

double fun(double x)
{
  return 2*std::exp(-x*x)/std::sqrt(M_PI);
}
