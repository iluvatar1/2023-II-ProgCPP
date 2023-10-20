#include <fstream>
#include <iostream>
#include <valarray>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

int main(void) {
  const int N = 5;
  std::valarray<double> x(N);

  // fill uniformly spaced N intervals in [0, 2pi]
  //double dx = (2*M_PI-0.0)/(N+1);
  //std::iota(std::begin(x), std::end(x), 0.0); // 0.0 1.0 2.0 3.0 4.0
  //x *= dx; // 0 dx 2dx 3dx ....

  // fill with random numbers in [0, 2pi]
  std::mt19937 gen(0);
  std::uniform_real_distribution<double> dist(0, 2*M_PI);
  auto init2 = [&dist, &gen](double & val){ val = dist(gen);};
  std::for_each(std::begin(x), std::end(x), init2);

  for(auto val : x) {
    std::cout << val << " ";
  }
  std::cout << "\n";

  // compute sin(x) and filter
  std::valarray<double> y = std::sin(x);
  std::valarray<double> x_filtered = x[std::abs(y) < 0.5];
  std::valarray<double> y_filtered = y[std::abs(y) < 0.5];

  // print
  //std::ofstream fout("data.txt");
  //std::for_each(std::begin(y_filtered), std::end(y_filtered),
    //            [&fout](double val) { fout << val << "\n"; });
  //fout.close();
  return 0;
}
