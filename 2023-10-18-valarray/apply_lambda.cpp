#include <iostream>
#include <valarray>
#include <cmath>

int main()
{
	std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

	auto change = [](int x) {return x%2 == 0 ? 3*x : 2*x;};

	v = v.apply(change);
	for (auto val : v) {
		std::cout << val << " ";
	}

    return 0;
}

