//
//  SimpleDisplayer.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/5/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef SimpleDisplayer_hpp
#define SimpleDisplayer_hpp

#include "soundFile.hpp"
#include "Displayer.hpp"
#include <stdio.h>
using namespace std;

class simpleDisplayer: public Displayer
{
public:
    simpleDisplayer();
    virtual void display(sound &s);
};
#endif /* SimpleDisplayer_hpp */
