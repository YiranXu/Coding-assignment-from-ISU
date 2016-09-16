//
//  SimpleDisplayer.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/5/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "SimpleDisplayer.hpp"
#include "Displayer.hpp"

//this class is for sndinfo program
simpleDisplayer::simpleDisplayer(){
    
}
void simpleDisplayer::display(sound &s){
    if(s.fileName!=""){
        cout<<"File name is: "<<s.fileName<<endl;
    }
    
  
    cout<<"File type is:   "<<s.fileType<<endl;
    cout<<"Sample rate is: "<<s.sampleRate<<endl;
    cout<<"Bit depth is:   "<<s.bitDepth<<endl;
    cout<<"Number of channels is: "<<s.channels<<endl;
    cout<<"Number of samples is:  "<<s.samples<<endl;
    cout<<"Length of sound is:    "<<s.length<<endl;
   
    cout<<"STARTdata"<<endl;

    for (int i = 0; i < s.samples; ++i)
    {
        for (int j = 0; j < s.channels; ++j)
        {
            //myfile <<(int)s.data[i][j] << ' ';
            cout<<int(s.data[i][j])<<" "; //test
        }
                      cout << endl;
     }
          //
    
}


