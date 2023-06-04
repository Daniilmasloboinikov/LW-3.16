//
//  histogram_internal.hpp
//  LW-1.16_
//
//  Created by MacBook on 14.05.2023.
//

#ifndef histogram_internal_hpp
#define histogram_internal_hpp

#include <stdio.h>
#include <vector>

using namespace std;

bool find_minmax(const std::vector<double>& numbers, double& min, double& max);

void show_histogram_text(std::vector<size_t> bins, double maxBin, size_t binCount);

vector<size_t> make_histogram(const vector<double>& numbers, size_t bincount, size_t numberCount);


#endif /* histogram_internal_hpp */
