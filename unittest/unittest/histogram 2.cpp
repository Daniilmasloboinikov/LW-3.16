//
//  histogram.cpp
//  LW-1.16_
//
//  Created by MacBook on 14.05.2023.
//

#include "histogram_internal.hpp"
#include <vector>
#include <string>
#include <iostream>


using namespace std;



void find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    max = min;
    for (int i = 1; i<numbers.size(); i++){
        if (numbers[i]<min){
            min = numbers[i];
        }
        if (numbers[i]>max){
            max = numbers[i];
        }
    }
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bincount, size_t numberCount){
    vector<size_t> bins(bincount);
    double min,max,step,minstep,maxstep, maxBin;
    find_minmax(numbers, min, max);
    step = (max-min)/bincount;
    minstep = min;
    maxBin = 0;
    for (size_t i=0; i<bincount; i++){
        maxstep = minstep + step;
        for (size_t j=0; j<numberCount; j++){
            if (i == bincount - 1){
                maxstep = max;
                if ((numbers[j]<=maxstep)&&(numbers[j]>=minstep)){
                    bins[i]++;
                }
            } else {
                if ((numbers[j]<maxstep)&&(numbers[j]>=minstep)){
                    bins[i]++;
                }
            }
        }
        minstep = maxstep;
        if (bins[i]>maxBin){
            maxBin = bins[i];
        }
    }
    //    show_histogram_text(bins, maxBin, bincount);
    return bins;
}



