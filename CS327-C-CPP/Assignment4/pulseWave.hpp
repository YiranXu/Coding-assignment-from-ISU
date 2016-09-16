//
//  pulseWave.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/11/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef pulseWave_hpp
#define pulseWave_hpp

#include "soundFile.hpp"
#include "waveform.hpp"
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <complex>
#include <cmath>
using namespace std;

class pulseWave: public waveform
{
public:
    pulseWave();
    ~pulseWave();
    //virtual void wave(double amplitude,
    //int frequency);
    virtual double value( double t,double duration,
                         int frequency);
    double pulseValue( double t,double duration,
                      int frequency, double fraction);
};

#endif /* pulseWave_hpp */
