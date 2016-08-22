//
//  sawtoothWave.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/11/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef sawtoothWave_hpp
#define sawtoothWave_hpp

#include "soundFile.hpp"
#include "waveform.hpp"
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <complex>
#include <cmath>
using namespace std;

class sawtoothWave: public waveform
{
public:
    sawtoothWave();
    ~sawtoothWave();
    //virtual void wave(double amplitude,
    //int frequency);
    virtual double value( double t,double duration,
                         int frequency);
};

#endif /* sawtoothWave_hpp */
