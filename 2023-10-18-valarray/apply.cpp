#include <iostream>
#include <valarray>
#include <cmath>

int change(int x);

int main()
{
	std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

	v = v.apply(change);
	for (auto val : v) {
		std::cout << val << " ";
	}

    return 0;
}

int change(int x){
    if (x%2 == 0){
		return 3*x;
    }
    else {
		return 2*x;
    }
}
