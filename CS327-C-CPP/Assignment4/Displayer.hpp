//
//  Displayer.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/5/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef Displayer_hpp
#define Displayer_hpp

#include "soundFile.hpp"
#include <stdio.h>
using namespace std;
class Displayer{
public:
    virtual void display(sound &s)=0;
};

#endif /* Displayer_hpp */
