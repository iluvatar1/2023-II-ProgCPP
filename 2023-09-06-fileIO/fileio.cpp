#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

double fun(double x);
void generate_data(double xmin, double xmax,
		   double dx);

int main(int argc, char **argv) {
  
  double XMIN = std::stod(argv[1]);
  double XMAX = std::stod(argv[2]);
  double DX = std::stod(argv[3]);
  generate_data(XMIN, XMAX, DX);
  
  return 0;
}

double fun(double x) {
  return std::sin(2*x);
}

void generate_data(double xmin, double xmax,
		   double dx)
{
  // TODO xmax >= xmin
  // TODO dx > 0.0 and dx <= xmax-xmin
  std::ofstream fout;
  fout.open("data.txt");
  fout.precision(15);
  fout.setf(std::ios::scientific);

  int a = 9;
  for (double x = xmin; x <= xmax; x = x+dx) {
    fout << a << "\t" << x << "\t" << fun(x) << "\n";
  }

  fout.close();
}
