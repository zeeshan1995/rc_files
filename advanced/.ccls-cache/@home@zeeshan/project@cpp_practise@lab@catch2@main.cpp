#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

unsigned int Factorial( unsigned int number ) {
        return number <= 1 ? number : Factorial(number-1)*number;
}

class foo{};
bool operator == (foo const &a, foo const & b)
{
    return true;
}
TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 13 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    REQUIRE(foo{} == foo{});
    foo{} == foo{};
}
