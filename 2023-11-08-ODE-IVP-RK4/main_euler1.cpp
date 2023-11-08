#include <iostream>
#include <valarray>
#include <cmath>
#include <cstdlib>
#include "integrator.h"

typedef std::valarray<double> state_t; // alias for state type

void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
{
  if (argc != 4) {
    std::cerr << "ERROR. Usage:\n" << argv[0] << " T0 TF DT" << std::endl;
    std::exit(1);
  }
  const double T0 = std::atof(argv[1]);
  const double TF = std::atof(argv[2]);
  const double DT = std::atof(argv[3]);

  const int N = 1;
  state_t y(N);

  // initial conditions
  y[0] = 1.5;

  // perform the actual integration
  // adapt to print to a file
  integrate_euler(fderiv, y, T0, TF, DT, print);

  return 0;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
  dydt[0] = 5*std::sin(t) + t;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << std::endl;
}
