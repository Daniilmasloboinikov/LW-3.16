#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "histogram_internal.hpp"
#include <iostream>

using namespace std;

TEST_CASE("distinct positive numbers") {
    double min = 0;
    double max = 0;
    find_minmax({1, 2}, min, max);
    CHECK(min == 1);
    CHECK(max == 2);
    
    vector<size_t> bins_check {2,2};
    vector<size_t> bins;

    
    bins = make_histogram({1,2,3,4}, 2, 4);
    
    for (int i=0; i<2; i++){
        CHECK(bins[i] == bins_check[i]);
    }
    
    
    
    
    
    
}
