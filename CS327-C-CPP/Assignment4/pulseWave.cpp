//
//  pulseWave.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/11/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "pulseWave.hpp"
#include "waveform.hpp"
#include <iomanip>
#include <limits>
#include <complex>
# define PI           3.14159265358979323846  /* pi */
pulseWave::pulseWave(){
    
    
}
pulseWave::~pulseWave(){
    
}

double pulseWave::value(double t, double duration,
                           int frequency){ //we do not use this function to generate wave because pulseWave requires the fraction of time, which introduces another parameter
    return 0;
}

double pulseWave::pulseValue( double t,double duration,
                  int frequency, double fraction){ //use this function to generate pulse wave
    if(t < 0 || t > duration)
    {
        
        return 0;
    }
    else
    {
        double sum=0;
        for(int i = 1; i < 200; i++)
            sum += (2/(double(i)*PI))*sin(PI*double(i)*fraction)*cos(2*PI*double(i)*double(frequency)*t);
        double value=fraction+sum+1;
        
        
        
        //double value=-(2*1/PI)*atan(cot(Value)+1;
        //cout<<"sine value"<<sineValue<<endl;//test
        return value;
    }

    
}
