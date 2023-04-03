//
//  main.cpp
//  ЛР-1.16
//
//  Created by MacBook on 05.03.2023.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    
    int numberCount,binCount;
    string s;
//    cout << "cin>> s";
    cin >> s;
    
    
//    cout << "write number count";
    cin >> numberCount;
    
   
    
    vector<double> numbers(numberCount);
    
    
    double max,min;
  
    if (s == "n"){
        for (int i=0; i<numberCount; i++){
            //        cout << "write number " << i;
            cin >> numbers[i];
            if (i==0){
                max = numbers[i];
                min = numbers[i];
            } else {
                if (numbers[i]>max){
                    max = numbers[i];
                }
                if (numbers[i]<min){
                    min = numbers[i];
                }
            }
        }
    }
    if (s == "y"){
        for (int i=0; i<numberCount; i++){
            //        cout << "write number " << i;
            int x;
            x = rand();
            for (int i=0; i<11; i++){
                x = x + rand();
            }
            numbers[i] = x;
            if (i==0){
                max = numbers[i];
                min = numbers[i];
            } else {
                if (numbers[i]>max){
                    max = numbers[i];
                }
                if (numbers[i]<min){
                    min = numbers[i];
                }
            }
        }
    }
    
    
    
//    cout << "write bin count";
    cin >> binCount;
    vector<size_t> bins(binCount);
    
    double step,minstep,maxstep;
    step = (max-min)/binCount;
    minstep = min;
    int maxBin = 0;
    for (size_t i=0; i<binCount; i++){
        maxstep = minstep + step;
        for (size_t j=0; j<numberCount; j++){
            if (i == binCount - 1){
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
        if (bins[i]>maxBin){
            maxBin = bins[i];
        }
        minstep = maxstep;
    }
    size_t height;
    for (size_t i=0; i<binCount; i++){
        if (maxBin>76){
            height = 76 * (static_cast<double>(bins[i]) / maxBin);
        }
        else {
            height = bins[i];
        }
        if ((bins[i]<100))
            cout << " ";
        if (bins[i]<10)
            cout<<" ";
        cout<<bins[i] << "|";
        for (size_t j=0; j<height; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
