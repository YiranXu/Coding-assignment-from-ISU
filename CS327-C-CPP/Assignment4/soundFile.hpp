//
//  soundFile.hpp
//  Homework4
//
//  Created by Yiran Xu on 11/25/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#ifndef soundFile_hpp
#define soundFile_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <vector>
#include <stdlib.h>

using namespace std;

class sound{
    public:
    string fileName;
    string fileType;
    int samples,sampleRate, channels,bitDepth;
    double length;
    double ** data;
    sound();
    sound(string soundFileName);
    ~sound(); //destructor
    
    //int getSamples(){return samples;}
};

class soundFileReader{
    public:
    bool cs229;
    bool startData;
    string soundFileName;
     FILE *fp;
    soundFileReader();  // set to zero
    //soundFileReader(string fileName);    // read file from file pointer fp
    
    soundFileReader(const soundFileReader &x);    // copy constructor
    
    ~soundFileReader(); //destructor
    
    void readSoundFile(sound &s);
    //void readData(sound &s); //call after readSoundFile
};





#endif /* soundFile_hpp */
