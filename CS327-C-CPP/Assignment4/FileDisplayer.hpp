//
//  FileDisplayer.hpp
//  Homework4
//
//  Created by Yiran Xu on 12/7/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

//This class is to output file
#ifndef FileDisplayer_hpp
#define FileDisplayer_hpp
#include "soundFile.hpp"
#include "Displayer.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

class FileDisplayer: public Displayer
{
public:
    FileDisplayer();
    virtual void display(sound &s);
    
};
#endif /* SimpleDisplayer_hpp */



