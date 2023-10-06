// g++ -g -fsanitize=address
#include <iostream>
#include <array>

int main(void)
{
  const int N = 10;
  //double data[N] {0};
  std::array<double, N> data;

  std::cout << "size: " << data.size() << std::endl;
  std::cout << "max_size: " << data.max_size() << std::endl;  
  std::cout << "sizeof(double): " << sizeof(double) << std::endl;
  std::cout << "&data[0]: " << &data[0] << std::endl;
  std::cout << "&data[1]: " << &data[1] << std::endl;
  std::cout << "&data[2]: " << &data[2] << std::endl;

  //std::cout << data[-1] << std::endl; // detected by sanitizers address
  //std::cout << data.at(-1) << std::endl; // detected by sanitizers address

// initialize the array with even numbers
  for(int ii = 0; ii < N; ++ii) {
    data[ii] = 2*ii;
  }


// print the array
  for(const auto & val : data) {
    std::cout << val << "  ";
  }
  std::cout << "\n";    

// compute the mean
  double sum = 0.0;
  for(auto val : data) {
    sum += val;
  }
  std::cout << "Average = " << sum/data.size() << std::endl;

  return 0;
}
