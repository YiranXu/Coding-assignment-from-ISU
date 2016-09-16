//
//  sawtoothWave.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/11/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "sawtoothWave.hpp"
#include "waveform.hpp"
#include <iomanip>
#include <limits>
#include <complex>
# define PI           3.14159265358979323846  /* pi */
sawtoothWave::sawtoothWave(){
    
    
}
sawtoothWave::~sawtoothWave(){
    
}

double sawtoothWave::value(double t, double duration, int frequency){
    if(t < 0 || t > duration)
    {
        
        return 0;
    }
    else
    {
        double cotValue=tan((PI/2)-(PI * ((double)frequency))* t);
        double value=-(2*1/PI)*atan(cotValue)+1;
        //cout<<"sine value"<<sineValue<<endl;//test
        return value;
    }
    
}