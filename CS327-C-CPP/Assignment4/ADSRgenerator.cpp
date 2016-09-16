//
//  ADSRgenerator.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/10/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "ADSRgenerator.hpp"

ADSRgenerator::ADSRgenerator(){
    bitdepth=0;
    peakVolume=0;
    sustainVolume=0;
}
ADSRgenerator::~ADSRgenerator(){


}

double ADSRgenerator::calcA(int bit, double peakL, double sustL, double time, double duration, double attackTime, double decayTime, double releaseTime){
    bitdepth=bit;
    int max=0;
    double a=0;
    if(bitdepth==8){  //max is half of the maximum value (2 to the power of bitdepth, then -1)
        max=127;
    }
    else if(bitdepth==16){
        max=32767;
    }
    else if(bitdepth==32){
        max=2147483647;
    }
    peakVolume=max*peakL;
    sustainVolume=max*sustL;
    if(time>=0 && time<attackTime){ //attack stage
        a=((time*peakVolume)/attackTime);
    }
    else if(time>=attackTime && time<attackTime+decayTime){ //decay stage
        double x=(attackTime+decayTime-time)*(peakVolume-sustainVolume)/decayTime;
        a=sustainVolume+x;
    }
    else if(time>=attackTime+decayTime && time<duration-releaseTime){ //sustain stage
        a=sustainVolume;
    }
    else if(time>=duration-releaseTime){ //s
        a=(duration-time)*sustainVolume/releaseTime;
    }
    bitdepth=0;
    peakVolume=0;
    sustainVolume=0;
    return a;
}