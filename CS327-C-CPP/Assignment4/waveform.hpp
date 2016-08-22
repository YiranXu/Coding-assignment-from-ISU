//
//  waveform.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/9/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef waveform_hpp
#define waveform_hpp


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include "soundFile.hpp"
using namespace std;

class waveform{
public:
    //virtual void wave(double amplitude,
                       //int frequency)=0;
    virtual double value(const double t, double duration,int frequency)=0;
};


#endif /* waveform_hpp */
