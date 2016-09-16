//
//  sinewave.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/9/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "sinewave.hpp"
#include "waveform.hpp"
#include <iomanip>
#include <limits>
#include <complex>
# define PI           3.14159265358979323846  /* pi */
sinewave::sinewave(){
    
    
}
sinewave::~sinewave(){
    
}

double sinewave::value(double t, double duration,
                       int frequency){
    if(t < 0 || t > duration)
    {
        
        return 0;
    }
    else
    {
        double sineValue=sin((2*PI * ((double)frequency))* t)+1.0;
        //cout<<"sine value"<<sineValue<<endl;//test
        return sineValue;
    }
   
}
