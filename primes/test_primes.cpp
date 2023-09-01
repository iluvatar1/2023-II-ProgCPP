#include <catch2/catch_test_macros.hpp>
#include "primes.h"

TEST_CASE( "Primes are computed", "[primes]" ) {
    REQUIRE( isprime(1) == false );
    REQUIRE( isprime(2) == true );
    REQUIRE( isprime(1007) == false );
    REQUIRE( isprime(10000000019) == true );
    REQUIRE( isprime(10000000020) == false );
    REQUIRE( isprime(50000000021) == true );
    REQUIRE( isprime(50000000022) == false);
}
