//
//  main.cpp
//  ЛР-1.16
//
//  Created by MacBook on 05.03.2023.
//

#include <iostream>
#include <vector>
#include <string>
#include "histogram.hpp"
#include "histogram_internal.hpp"
#include "svg.hpp"


using namespace std;

struct Input {
    std::vector<double> numbers;
    size_t binCount;
    size_t numberCount;

};


Input input_data(){
    Input in;
    cout << "write number count";
    cin >> in.numberCount;
    
    in.numbers.resize(in.numberCount);
    
    for (int i=0; i<in.numberCount; i++){
        cout << "write number " << i+1;
        cin >> in.numbers[i];
    }
    
    cout << "bin count =";
    cin >> in.binCount;
    return in;
}

int main(){
    vector<size_t> bins;
    auto in = input_data();
    bins = make_histogram(in.numbers, in.binCount, in.numberCount);
    show_histogram_svg(bins, in.binCount);
}
