#include <iostream>
#include <string>
#include "primes.h"
// ./a.out imin imax

int main(int argc, char **argv) {
    long imin = std::stol(argv[1]);
    long imax = std::stol(argv[2]);
    for(long ii = imin; ii <= imax; ++ii) {
        if (isprime(ii) and isprime(ii+4)) {
            std::cout << "(" << ii << "," << ii+4 << ") ";
        }
    }
    std::cout << "\n";
    return 0;
}
