//
//  histogram.cpp
//  LW-1.16_
//
//  Created by MacBook on 14.05.2023.
//

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





