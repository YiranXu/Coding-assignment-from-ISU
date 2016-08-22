//
//  FileDisplayer.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/7/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "FileDisplayer.hpp"
#include "Displayer.hpp"
#include "SimpleDisplayer.hpp"
FileDisplayer:: FileDisplayer(){
    
}

void FileDisplayer::display(sound &s){
    ofstream myfile;
    myfile.open (s.fileName.c_str());
    myfile<<"Cs229"<<endl;
    
    
    myfile<<"Samples   "<<s.samples<<endl;
    myfile<<"BitRes   "<<s.bitDepth<<endl;
    myfile<<"channels  "<<s.channels<<endl;
    myfile<<"SampleRate  "<<s.sampleRate<<endl;
    
    myfile<<"STARTdata"<<endl;
    
    for (int i = 0; i < s.samples; ++i)
    {
        for (int j = 0; j < s.channels; ++j)
        {
            myfile <<(int)s.data[i][j] << ' ';
          //  cout<<s.data[i][j] <<endl; //test
        }
       myfile << endl;
    }
    //myfile<<"Lengthe of sound is: "<<s.length<<endl;
    
    //myfile << "Writing this to a file.\n";
    myfile.close();
   cout<<"A output file '"<<s.fileName.c_str()<< "' is generated."<<endl;
}
