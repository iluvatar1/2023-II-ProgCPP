#include <iostream>
#include <string>
#include "primes.h"
// ./a.out imin imax

int main(int argc, char **argv) {
    long imin = std::stol(argv[1]); 
    long imax = std::stol(argv[2]);
    std::cout << isprime(1007) << "\n";
    std::cout << isprime(10000000019) << "\n";
    for(long ii = imin; ii <= imax; ++ii) {
        if (isprime(ii)) {
            std::cout << ii << " ";
        }
    }
    std::cout << "\n";
    return 0;
}
