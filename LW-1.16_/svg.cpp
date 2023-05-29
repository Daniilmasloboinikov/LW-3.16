//
//  svg.cpp
//  LW-1.16_
//
//  Created by MacBook on 14.05.2023.
//

#include "svg.hpp"
#include <iostream>
#include <fstream>
#include "histogram_internal.hpp"
using namespace std;



void
svg_begin(double width, double height) {
    ofstream file;
    file.open("/Users/macbook/Desktop/универ/lab/2_sem/LW-1.16_/LW-1.16_/marks.svg");
    file << "<?xml version='1.0' encoding='UTF-8'?>\n";
    file << "<svg ";
    file << "width='" << width << "' ";
    file << "height='" << height << "' ";
    file << "viewBox='0 0 " << width << " " << height << "' ";
    file << "xmlns='http://www.w3.org/2000/svg'>\n";
    file.close();
}

void
svg_end() {
    ofstream file;
    file.open("/Users/macbook/Desktop/универ/lab/2_sem/LW-1.16_/LW-1.16_/marks.svg", ios_base::app);
    file << "</svg>\n";
    file.close();
}

void svg_text(double left, double baseline, string text){
    ofstream file;
    file.open("/Users/macbook/Desktop/универ/lab/2_sem/LW-1.16_/LW-1.16_/marks.svg", ios_base::app);
    file << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string color){
    
    ofstream file;
    file.open("/Users/macbook/Desktop/универ/lab/2_sem/LW-1.16_/LW-1.16_/marks.svg", ios_base::app);
    file << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='"<< color <<"' fill='"<< color <<"'/>";
}

void show_histogram_svg(const vector<size_t>& bins, size_t binCount) {
    
    double max;
    
    max = 0;
    for (int i = 0; i<bins.size(); i++){
        if (bins[i]>max){
            max = bins[i];
            
        }
    }
    
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
//    string color[5] = { "red", "green", "blue", "black", "orange"};
    string colors[binCount];
    
    cout << "choose colors: red, green, blue, black, orange" << "\n";
    for(int i=0; i<binCount; i++){
        cout << "choose color " << i+1 << ":";
        cin >> colors[i];
    }
    
    double top = 0;
    svg_begin(400, 300);
    int i=0;
    for (size_t bin : bins) {
        const double bin_width = bin *(IMAGE_WIDTH-TEXT_WIDTH)/max;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, colors[i]);
        top += BIN_HEIGHT;
        i += 1;
    }
    svg_end();
}


                                                    

