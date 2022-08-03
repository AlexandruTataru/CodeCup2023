#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <lib.hpp>

TEST_CASE("Quick check", "[defines]")
{
    REQUIRE(ROW_TO_LETTER(0) == 'A');
}