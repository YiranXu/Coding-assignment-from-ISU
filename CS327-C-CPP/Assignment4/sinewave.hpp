//
//  sinewave.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/9/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef sinewave_hpp
#define sinewave_hpp

#include "soundFile.hpp"
#include "waveform.hpp"
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <complex>
using namespace std;
class sinewave: public waveform
{
public:
    sinewave();
    ~sinewave();
    //virtual void wave(double amplitude,
                       //int frequency);
    virtual double value( double t,double duration,
                         int frequency);
};

#endif /* sinewave_hpp */
