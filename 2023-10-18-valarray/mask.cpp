#include <iostream>
#include <valarray>

int main()
{
  std::valarray<int> data = {10,1,2,3,4,5,6,7,8,9};

  std::cout << "Initial valarray: ";
  for(int n: data) std::cout << n << ' ';
  std::cout << '\n';

  /*
  for (int ii = 0; ii < data.size(); ++ii) {
	  if (data[ii] > 5) {
		  data[ii] = -1;
	  }
  }
  */

  //data > 5 -> {True, False , False, False , False, False, True, True, True, True}
  data[data > 5] = -1; // valarray<bool> overload of operator[]
  // the type of data>5 is std::valarray<bool>
  // the type of data[data>5] is std::mask_array<int>

  std::cout << "After v[v>5]=-1:  ";
  for(int n = 0; n < data.size(); ++n)
    std::cout << data[n] << ' ';  // regular operator[]
  std::cout << '\n';
}
