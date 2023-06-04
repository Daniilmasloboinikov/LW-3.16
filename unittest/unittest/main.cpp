#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "histogram_internal.hpp"
#include <iostream>

using namespace std;

TEST_CASE("distinct positive numbers") {
    double min = 0;
    double max = 0;
    bool f;
    f = find_minmax({1, 2}, min, max);
    CHECK(min == 1);
    CHECK(max == 2);
    CHECK(f == true);
}

TEST_CASE("distinct nule numbers") {
    double min = 0;
    double max = 0;
    CHECK(find_minmax({}, min, max) == false);

}

TEST_CASE("distinct nule numbers") {
    double min = 0;
    double max = 0;
    bool f;
    f = find_minmax({1}, min, max);
    CHECK(min == 1);
    CHECK(max == 1);
    CHECK(f == true);

}

TEST_CASE("distinct nule numbers") {
    double min = 0;
    double max = 0;
    bool f;
    f = find_minmax({-1,-2}, min, max);
    CHECK(min == -2);
    CHECK(max == -1);
    CHECK(f == true);

}

TEST_CASE("distinct nule numbers") {
    double min = 0;
    double max = 0;
    bool f;
    f = find_minmax({1,1,1,1}, min, max);
    CHECK(min == 1);
    CHECK(max == 1);
    CHECK(f == true);

}


