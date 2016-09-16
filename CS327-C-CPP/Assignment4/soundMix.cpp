//
//  soundMix.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/7/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "soundMix.hpp"
soundMix::soundMix(){
    
}
soundMix::~soundMix()
{
    //delete cs229;
    
}
void soundMix::mix(sound allSound[], sound &sC, int numberOfSound, float multArr[]){
    
    //check whether channels are the same
    //Number of channesl
    for(int i=0;i<numberOfSound;i++){
        if(i==numberOfSound-1){
            break;
        }
        if(allSound[i].channels!=allSound[i+1].channels){
            cout<<"Number of channels in the input files are different. cannot mix."<<endl;
            //sameChannel=false;
            return;
        }
    }
    sC.channels=allSound[0].channels;
    
    //bit depth
    int max=0;
    for(int i=0;i<numberOfSound;i++){
        if(allSound[i].bitDepth > max)
            max = allSound[i].bitDepth;
    }
    sC.bitDepth=max;
    
    //number of samples  //keep the max number of samples
    sC.samples=0;
    for(int i=0;i<numberOfSound;i++){
        if(allSound[i].samples > sC.samples)
            sC.samples= allSound[i].samples;
    }
   // cout<<sC.samples<<endl;//test
    
    //SampleRate
    for(int i=0;i<numberOfSound;i++){
        if(i==numberOfSound-1){
            break;
        }
        if(allSound[i].sampleRate!=allSound[i+1].sampleRate){
            cout<<"Number of sample Rate in the input files are different. cannot mix."<<endl;
            //sameChannel=false;
            return;
        }
    }
    sC.sampleRate=allSound[0].sampleRate;
    
    //length //keep the max length
    sC.length=0;
    for(int i=0;i<numberOfSound;i++){
        if(allSound[i].length > sC.length)
            sC.length= allSound[i].length;

    }
    //cout<<sC.length<<endl;//test

    //data
    //Assume channel is one
    //First multiply sample with specified number
    sC.data= new double*[sC.samples];
    for(int i = 0; i < sC.samples; ++i) {
        sC.data[i] = new double[sC.channels];
    }
    int countLine=0;
    for(int i=0;i<numberOfSound;i++){
        
        for(int a = 0; a<allSound[i].samples; a++)
        {
            //memcpy(&sC.data[countLine], &allSound[i].data[a], sizeof(sC.data[0]));
            for (int c = 0; c < sC.channels; c++) //test
            {
                allSound[i].data[a][c]=allSound[i].data[a][c]*(multArr[i]);
                //dd if 
        //        cout<<allSound[i].data[a][c]<<endl;//test
            }
            countLine++;
            //cout<<*(allSound[0].data[a])<<endl; //test
            /*
             for (int c = 0; c < sC.channels; c++) //test
             {
             sC.data[a][c]=allSound[i].data[a][c];
             cout << allSound[i].data[a][c] << "\n";
             }
             */
        }
        
    }
    //Adding all together
     for(int i = 0; i < sC.samples; ++i) {
         for(int c = 0; c < sC.channels; c++){
             for(int a=0;a<numberOfSound;a++ ){
                 //cout<<allSound[a].data[i][c]<<endl;
                 sC.data[i][c]+=allSound[a].data[i][c];
                 
     //            cout<<sC.data[i][c]<<endl;//test
             }
             
         }
         
     }
   // cout<<"sC data:"<<endl;
    for (int c = 0; c < sC.samples; c++) //test
    {
        for (int cc = 0; cc < sC.channels; cc++){
 //           cout << sC.data[c][cc] << "\n";
        }
    }

    
}
