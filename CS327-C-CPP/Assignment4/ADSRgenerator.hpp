//
//  ADSRgenerator.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/10/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef ADSRgenerator_hpp
#define ADSRgenerator_hpp

#include <stdio.h>
#include "soundFile.hpp"
using namespace std;

class ADSRgenerator{
    
public:
    int bitdepth;
    double peakVolume;
    double sustainVolume;
    ADSRgenerator();
    ~ADSRgenerator();
    double calcA(int bit, double peakV, double sustV, double time, double duration, double attackTime, double decayTime, double releaseTime);
};

#endif /* ADSRgenerator_hpp */
