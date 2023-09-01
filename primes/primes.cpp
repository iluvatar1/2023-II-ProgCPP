#include "primes.h"

bool isprime(long n) {
    if ( 1 == n ) {
        return false;
    }
    bool flag = true;
    for(long ii = 2; ii*ii <= n; ii++) {
        if (n%ii == 0) { // if ii is a divisor of n
            flag = false;
            break;
        }
    }
    return flag;
}
