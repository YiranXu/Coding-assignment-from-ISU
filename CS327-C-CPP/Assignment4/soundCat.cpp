//
//  soundCat.cpp
//  Homework4
//
//  Created by Yiran Xu on 12/6/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "soundCat.hpp"
#include <cstring>

soundCat::soundCat(){
    
}
soundCat::~soundCat()
{
    //delete cs229;
    
}
//concatenate all sound in allSound[] array into single sound
void soundCat::cat(sound allSound[],sound &sC, int numberOfSound){
    //check whether channels are the same
    //Number of channesl
    for(int i=0;i<numberOfSound;i++){
        if(i==numberOfSound-1){
            break;
        }
        if(allSound[i].channels!=allSound[i+1].channels){
            cout<<"Number of channels in the input files are different. cannot concatenate."<<endl;
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
    
    //number of samples
    sC.samples=0;
    for(int i=0;i<numberOfSound;i++){
        sC.samples+=allSound[i].samples;
    }
    //cout<<sC.samples<<endl;//test
    
    //SampleRate
    for(int i=0;i<numberOfSound;i++){
        if(i==numberOfSound-1){
            break;
        }
        if(allSound[i].sampleRate!=allSound[i+1].sampleRate){
            cout<<"Number of sample Rate in the input files are different. cannot concatenate."<<endl;
            //sameChannel=false;
            return;
        }
    }
    sC.sampleRate=allSound[0].sampleRate;
    
    //length
    sC.length=0;
    for(int i=0;i<numberOfSound;i++){
        sC.length+=allSound[i].length;
    }
    // cout<<sC.length<<endl;//test
    //data
    //bb
    int temp=sC.samples;
    sC.data= new double*[temp];
    for(int i = 0; i < sC.samples; i++) {
        sC.data[i] = new double[sC.channels];
    }
    int countLine=0;
    for(int i=0;i<numberOfSound;i++){
        
        for(int a = 0; a<allSound[i].samples; a++)
        {
            memcpy(&sC.data[countLine], &allSound[i].data[a], sizeof(sC.data[0]));
        //bb    for (int c = 0; c < sC.channels; c++) //test
         //   {
         //       cout << sC.data[countLine][c] << "\n";
         //   }
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
   // cout<<"Print sC data"<<endl;
    //test
    for (int c = 0; c < sC.samples; c++) //test
    {
        for (int cc = 0; cc < sC.channels; cc++){
   //         cout << sC.data[c][cc] << "\n";
        }      
    }

    /*
    size_t size=allSound->ize();
    for
    samples=0;
    sampleRate=0;
    channels=0;
    bitDepth=0;
    length=0;
    fileName=soundFileName;
    fileType="";
*/
}
