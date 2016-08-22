//
//  soundCat.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/6/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef soundCat_hpp
#define soundCat_hpp

#include <stdio.h>
#include <cstring>
#include "soundFile.hpp"
#include "Displayer.hpp"
#include "SimpleDisplayer.hpp"
using namespace std;

class soundCat:public sound
{
    
public:
    
    soundCat();
    ~soundCat();
    void cat(sound allSound[], sound &sC, int numberOfSound);
};


#endif /* soundCat_hpp */
