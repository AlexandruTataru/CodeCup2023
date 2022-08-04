#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <lib.hpp>

TEST_CASE("Rows to letters", "[defines]")
{
    REQUIRE(ROW_TO_LETTER(0) == 'A');
    REQUIRE(ROW_TO_LETTER(1) == 'B');
    REQUIRE(ROW_TO_LETTER(2) == 'C');
    REQUIRE(ROW_TO_LETTER(3) == 'D');
    REQUIRE(ROW_TO_LETTER(4) == 'E');
    REQUIRE(ROW_TO_LETTER(5) == 'F');
    REQUIRE(ROW_TO_LETTER(6) == 'G');
}

TEST_CASE("Columns to letters", "[defines]")
{
    REQUIRE(COL_TO_LETTER(0) == 'a');
    REQUIRE(COL_TO_LETTER(1) == 'b');
    REQUIRE(COL_TO_LETTER(2) == 'c');
    REQUIRE(COL_TO_LETTER(3) == 'd');
    REQUIRE(COL_TO_LETTER(4) == 'e');
    REQUIRE(COL_TO_LETTER(5) == 'f');
    REQUIRE(COL_TO_LETTER(6) == 'g');
}

TEST_CASE("Letters to rows", "[defines]")
{
    REQUIRE(LETTER_TO_ROW('A') == 0);
    REQUIRE(LETTER_TO_ROW('B') == 1);
    REQUIRE(LETTER_TO_ROW('C') == 2);
    REQUIRE(LETTER_TO_ROW('D') == 3);
    REQUIRE(LETTER_TO_ROW('E') == 4);
    REQUIRE(LETTER_TO_ROW('F') == 5);
    REQUIRE(LETTER_TO_ROW('G') == 6);
}

TEST_CASE("Letters to columns", "[defines]")
{
    REQUIRE(LETTER_TO_COL('a') == 0);
    REQUIRE(LETTER_TO_COL('b') == 1);
    REQUIRE(LETTER_TO_COL('c') == 2);
    REQUIRE(LETTER_TO_COL('d') == 3);
    REQUIRE(LETTER_TO_COL('e') == 4);
    REQUIRE(LETTER_TO_COL('f') == 5);
    REQUIRE(LETTER_TO_COL('g') == 6);
}