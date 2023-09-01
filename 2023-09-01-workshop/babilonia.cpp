#include <iostream>
#include <string>

double babilonian_root(int iter);

int main(int argc, char **argv) {
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  // leer el numero de iteraciones
  int niter = std::stoi(argv[1]);
  
  double root = babilonian_root(niter);
  std::cout << niter << "\t" << root << "\n";
  return 0;
}

double babilonian_root(int iter)
{
  double x = 1.0;
  for (int n = 1; n <= iter; n = n+1) {
    x = (x + 2.0/x)/2;
  }
  return x;
}
