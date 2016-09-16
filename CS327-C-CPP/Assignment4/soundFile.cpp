//
//  soundFile.cpp
//  Homework4
//
//  Created by Yiran Xu on 11/25/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//

#include "soundFile.hpp"
//implement constructor

sound::sound(){
    samples=0;
    sampleRate=0;
    channels=0;
    bitDepth=0;
    length=0;
    fileName="";
    fileType="";

}
sound::sound(string soundFileName){
    samples=0;
    sampleRate=0;
    channels=0;
    bitDepth=0;
    length=0;
    fileName=soundFileName;
    fileType="";
}

sound::~sound(){
    //
}
soundFileReader::soundFileReader(){
    cs229=false;
    startData=false;
    soundFileName="";
}

//open file
//soundFileReader::soundFileReader(string soundFileName){
   // fileName=soundFileName;
     //fp=fopen(fileName,"r");

//}

soundFileReader::~soundFileReader()
{
    //delete cs229;
    
}

void soundFileReader::readSoundFile(sound &s){
    
    
    
    
    bool hasSampleRate,hasChannels,hasBitDepth;//must specify these three keywords
    int sampleRateTime=0, channelsTime=0,bitDepthTime=0,sampleNumberTime=0;//can only appear once
    int dataLine=0;//How many lines in data section (number of samples)
    string t("#");
    string keyword1("samples");
    string keyword2("channels");
    string keyword3("bitres");
    string keyword4("samplerate");
    string keyword5("startdata");
    soundFileName=s.fileName;
    string linebuffer;
    int linecount=0;
//    cout<<soundFileName<<endl;  //test
    ifstream infile(soundFileName.c_str());
    if(!infile){
        cout<<"Cannot open sound file."<<endl;
        exit(1);
    }
    if(soundFileName.find(".wav") != std::string::npos){
        s.fileType=".wav file";
    }
    else if(soundFileName.find(".cs229") != std::string::npos){
         s.fileType=".cs229 file";
    }
    else{
        cout<<"invalid file type"<<endl;
    }
    while(getline(infile,linebuffer)){
        if(startData==false){
     //       cout<<linebuffer<<endl; //test
            linecount++;
            
            //int test1= linebuffer.compare("Cs229");
            //cout<<test1<<endl;
            
            if(linecount==1 && (linebuffer.compare("Cs229") != 0&& linebuffer.compare("CS229") == 0 && linebuffer.compare("cs229") != 0 && linebuffer.compare("cS229") != 0)){ //the first line is not Cs229
                cout<<"First line is not Cs229. Cannot recognize the file"<<endl;
                break;
            }
            else{  //else 1
                cs229=true;
                
                //if empty line, then continue
                if(linebuffer.length()==0){
                    continue;
                }
                //if starts with #, ignore
                
                
                //cout<<linebuffer.compare(0, sr.length(), t)<<endl;//test
                //cout<<linebuffer.find(keyword1)<<endl;
                
                if (linebuffer.compare(0, t.length(), t) == 0) //check whether the line starts with "#"
                {
                    continue; //if starting with "#", the line should be ignored
                }
                else //else 2
                    
                {
                    for(int i = 0; i < linebuffer.size(); i++)
                    {
                        linebuffer[i] = tolower(linebuffer[i]); //change all the characters in the line into lower case for case insensitive comparison later
                    }
              //      cout<<linebuffer<<endl;//test
                    if(linebuffer.find(keyword1) == 0)
                    {  //find "samples"
                        
                        sampleNumberTime++;
                        if(sampleNumberTime>1){ //can only appear once
                            cout<<"Sample Number can only be specified once"<<endl;
                            break;
                        }
                        istringstream ss(linebuffer);
                        string token;
                        int i=0;
                        while(ss>>token){
                            i++;
                //            cout << token << endl;//test
                            
                            
                            if(i==2){
                                s.samples = atoi(token.c_str());
                                if ( !s.samples && token != "0" ) {
                                    cout<<"The value specified is not an integer."<<endl;
                                    
                                }
                                break;
                            }
                            
                        }//end while (ss>>token)
                    } //end if(linebuffer.find(keyword1) == 0)
                    else if(linebuffer.find(keyword2) == 0){ //find "channels"
                        channelsTime++;
                        if(channelsTime>1){ //can only appear once
                            cout<<"Channel Number can only be specified once"<<endl;
                            break;
                        }
                        istringstream ss(linebuffer);
                        string token;
                        int i=0;
                        while(ss>>token){
                            i++;
                  //          cout << token << endl;//test
                            if(i==2){
                                s.channels = atoi(token.c_str());
                                if ( !s.channels && token != "0" ) {
                                    cout<<"The value specified is not an integer."<<endl;
                                    
                                }
                                break;
                            }
                            
                        }//end while (ss>>token)
                    }
                    else if(linebuffer.find(keyword3) == 0){
                        bitDepthTime++;
                        if(bitDepthTime>1){ //can only appear once
                            cout<<"Bit Depth Number can only be specified once"<<endl;
                            break;
                        }
                        istringstream ss(linebuffer);
                        string token;
                        int i=0;
                        while(ss>>token){
                            i++;
                    //        cout << token << endl;//test
                            if(i==2){
                                s.bitDepth = atoi(token.c_str());
                                if(s.bitDepth!=8 || s.bitDepth!=16 || s.bitDepth!=32){
                                    cout<<"Bit depth is not 8, or 16, or 32.Illegal!"<<endl;
                                }
                                if ( !s.bitDepth && token != "0" ) {
                                    cout<<"The value specified is not an integer."<<endl;
                                    
                                }
                                break;
                            }
                            
                        }//end while (ss>>token)
                    }
                    else if(linebuffer.find(keyword4) == 0){
                        sampleRateTime++;
                        if(sampleRateTime>1){ //can only appear once
                            cout<<"Sample Rate Number can only be specified once"<<endl;
                            break;
                        }
                        istringstream ss(linebuffer);
                        string token;
                        int i=0;
                        while(ss>>token){
                            i++;
                     //       cout << token << endl;//test
                            if(i==2){
                                s.sampleRate = atoi(token.c_str());
                                if ( !s.sampleRate && token != "0" ) {
                                    cout<<"The value specified is not an integer."<<endl;
                                    
                                }
                                break;
                            }
                            
                        }//end while (ss>>token)
                    }
                    else if(0==linebuffer.compare("startdata")){ //began to read data
                        startData=true;
                        if(sampleRateTime==1 && channelsTime==1 && bitDepthTime==1){ //check whether they only appear once
                            continue;
                            
                        }
                        else{
                            cout<<"Must specify sample rate, number of channels and bit depth."<<endl;
                            exit(1);
                        }
                    }
                    
                    
                }//end else 2
            } //end else 1
            
        } //end
        else{ //read data
           // cout<<linebuffer<<endl; //test
            if(linebuffer.length()==0 && dataLine==0){
                cout<<"There should be no empty line in data section or there is no data in data section"<<endl;
            }
            if(linebuffer.length()!=0){
                dataLine++;
               // cout<<"lines in data:"<<dataLine<<endl;
                /*
                count++;
                memcpy(s.data, p, oldcount * sizeof(int));
                delete [] p;
                p = s.data;
                oldcount = count; // for use later

                
                s.data[dataLine]=new int[s.channels];
                istringstream ss(linebuffer);
                string token;
                int i=0;
                while(ss>>token){
                  
                    s.data[dataLine][i]=atoi(token.c_str());
                    cout<<s.data[dataLine][i]<<endl;//test
                    if(dataLine>0){
                        cout<<s.data[dataLine-1][i]<<endl;}
                      i++;
                }
                if(s.channels!=i){
                    cout<<"Number of samples specified does not match with data"<<endl;
                    break;
                }
                 */
               
            }
            
        }
        }//end while
   
    if(sampleNumberTime==1){
        if(s.samples!=dataLine){
            cout<<"Specified number of samples does not match sample data in the file"<<endl;
            exit(1);
        }
    }
     //dataLine++;
    s.data= new double*[dataLine];
    for(int i = 0; i < dataLine; ++i) {
        s.data[i] = new double[s.channels];
    }
    //read data
    ifstream infile2(soundFileName.c_str());
    startData=false;
    int dataCount=0;
    while(getline(infile2,linebuffer)){
        for(int i = 0; i < linebuffer.size(); i++)
        {
            linebuffer[i] = tolower(linebuffer[i]); //change all the characters in the line into lower case for case insensitive comparison later
        }
        if(startData==false){
            if(0!=linebuffer.compare("startdata")){
                continue;
            }
            else{
                startData=true;
                
            }
        }
        else{
            //s.data[dataCount]=new int[s.channels];
            istringstream ss(linebuffer);
            
            string token;
            int i=0;
            while(ss>>token){
                
                s.data[dataCount][i]=atoi(token.c_str());
                //if(s.bitDepth){
                    
                //}
     //           cout<<s.data[dataCount][i]<<endl;//test
                //if(dataCount>0){
                    //cout<<s.data[dataCount-1][i]<<endl;} //test
                i++;
            }
           dataCount++;
        }
       
    }
    s.length=(double)(s.samples)/(s.sampleRate);
    cs229=false;
    startData=false;
    soundFileName="";
    fp=NULL;
    infile.close();
}







