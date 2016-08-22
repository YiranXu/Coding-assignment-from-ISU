//
//  soundMix.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/7/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef soundMix_hpp
#define soundMix_hpp

#include <stdio.h>
#include "soundFile.hpp"
using namespace std;

class soundMix{
    
public:
    soundMix();
    ~soundMix();
    void mix(sound allSound[], sound &sC, int numberOfSound, float multArr[]);
};


#endif /* soundMix_hpp */
