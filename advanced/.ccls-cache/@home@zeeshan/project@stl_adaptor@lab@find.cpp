
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <vector>
#include <stl_adaptor/algorithm.hpp>

std::vector<int> nums {2, 1, 2, 3, 4, 5, 2, 3, 4, 2};

//template<typename InputItr>
//bool operator == (std::pair<InputItr, std::size_t> const & a, std::pair<InputItr, std::size_t> const & b)
//{
//    return a.first == b.first and a.second == b.second;
//}
//class foo{};
//bool operator == (foo const &a, foo const & b)
//{
//        return true;
//}
//TEST_CASE( "Factorials are computed", "[factorial]" ) {
//                        REQUIRE(foo{} == foo{});
//                            foo{} == foo{};
//}
//
TEST_CASE( "Counted find", "[find]" ) { 
    REQUIRE( stl_adaptor::find(nums.begin(), std::distance(nums.begin(), nums.end()), 2) == std::make_pair(nums.begin(), std::size_t{10}));
    //REQUIRE( Factorial(2) == 2 );
    //REQUIRE( Factorial(3) == 6 );
    //REQUIRE( Factorial(10) == 3628800 );
}
