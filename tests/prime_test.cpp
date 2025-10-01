

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/prime.hpp"

#include <expected>
/*
THE FOLLOWING FUNCTIONS NEED UNIT TESTS

    bool wasOriginalPrime(const std::vector<int> &check) const;
    std::vector<int> find_factors();
    std::string wasCompositeOrPrime() const;
    std::string factorListString() const;
    std::string prettyPrint_myFactors() const;

*/

Factorize factors0(0);
Factorize factors1(1);
Factorize factorsNeg22(-22);

Factorize factors3(3);
Factorize factors10(10);
Factorize factors52(52);

TEST_CASE( "An attempt to find factors of 0 returns an empty vector." ) {
    REQUIRE( factors0.find_factors().empty());
}
TEST_CASE( "An attempt to find factors of 1 returns an empty vector." ) {
    REQUIRE( factors1.find_factors().empty());
}
TEST_CASE( "An attempt to find factors of -22 returns an empty vector." ) {
    REQUIRE( factorsNeg22.find_factors().empty());
}

TEST_CASE( "The primes of 3 are 3 and 1" ) {
    REQUIRE( factors3.find_factors().at(0) == 1 );
    REQUIRE( factors3.find_factors().at(1) == 3 );
}
TEST_CASE( "The primes of 10 are 2 and 5" ) {
    REQUIRE( factors10.find_factors().at(0) == 2 );
    REQUIRE( factors10.find_factors().at(1) == 5 );
}
TEST_CASE( "The primes of 52 are 2, 2, and 13" ) {
    REQUIRE( factors10.find_factors().at(0) == 2 );
    REQUIRE( factors10.find_factors().at(1) == 2 );
    REQUIRE( factors10.find_factors().at(2) == 13 );
}

