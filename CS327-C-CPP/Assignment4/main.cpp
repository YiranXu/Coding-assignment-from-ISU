//
//  main.cpp
//  Homework4
//
//  Created by Yiran Xu on 11/25/15.
//  Copyright © 2015 Yiran Xu. All rights reserved.
//
#include "soundFile.hpp"
#include "Displayer.hpp"
#include "SimpleDisplayer.hpp"
#include "FileDisplayer.hpp"

#include "sinewave.hpp"
#include "ADSRgenerator.hpp"
#include "triangleWave.hpp"
#include "sawtoothWave.hpp"
#include "pulseWave.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//#include <array>
#include "soundCat.hpp"
#include "soundMix.hpp"
using namespace std;



enum string_code {
    bits_in,
    sr_in,
    ff,
    tt,
    vv,
    aa,
    dd,
    ss,
    rr,
    sine,
    tri,
    saw,
    pulse,
    pf_in,
    oo
};

string_code hashit (string const& inString) {
	if (inString == "--bits") return bits_in;
	if (inString == "--sr") return sr_in;
    if (inString == "-f") return ff;
    if (inString == "-t") return tt;
	if (inString == "-v") return vv;
	if (inString == "-a") return aa;
	if (inString == "-d") return dd;
	if (inString == "-s") return ss;
	if (inString == "-r") return rr;
	if (inString == "--sine") return sine;
	if (inString == "--triangle") return tri;
	if (inString == "--sawtooth") return saw;
	if (inString == "--pulse") return pulse;
	if (inString == "--pf") return pf_in;
        if (inString == "-o") return oo;
}

int main(int argc, char * argv[]) {
   
  //Add code for passing argument
   //Now:ask reader to input
                cout<<endl;
			cout<<endl; 
  		cout<<"   *********************************************************************************"<<endl;
                cout<<"   *   Created by Yiran Xu.  Copyright © 2015 Yiran Xu. All rights reserved.       *"<<endl;
	 	cout<<"   *   The programs including 'sndinfo','sndcat','sndmix','sndgen' are available.  *"<<endl;
	  	cout<<"   *   Type '-h' for detailed information about these problem.                     *"<<endl;
	  	cout<<"   *********************************************************************************"<<endl;
		cout<<endl;
    int i_argc;
    
    int flag_in = 0;
    int ii;
    int numberOfSound =2 ;//edit later when command line
    string filename; 
    std::vector<std::string> fileNamesArr;
    std::vector<std::string> fileNames_in;


	// Convert all capital letter to small here
	/*
          string linebuffer;
          for(int j=0;j<argc;j++){
               linebuffer=argv[j];
           
             
           for(int i = 0; i < linebuffer.size(); i++)
           {
             linebuffer[i] = tolower(linebuffer[i]); //change all the characters in the line into lower case for case insensitive comparison later
           }
            
              memcpy(argv[j], linebuffer.c_str(), linebuffer.length()+1);
             
          } 
         //delete [] linebuffer; 
         */   
	// -----
  
	if(argc==1||(argc==2&&strcmp(argv[1],"-h")==0)){
		cout<<"Please see general information below for the codes: "<<endl;
                  cout<<endl;
		 cout<<"Program [Switches] Argument_1 ... Argument_n"<<endl;
                  cout<<endl;
		 cout<<"Program:  "<<endl;
		  cout<<"   sndinfo   "<<"  This program reads all sound files passed as arguments, and for each one, displays the following."<<endl;
		  cout<<"   sndcat    "<<"  This program reads all sound files passed as arguments, and writes a single sound file that is concatenation of the inputs."<<endl;
		  cout<<"   sndmix    "<<"  This program reads all sound files passed as arguments, and mixes them into a single sound file."<<endl;
		  cout<<"   sndgen    "<<"  This program produces a sound of a specified frequency and wavefrom using a simple ADSR envelope."<<endl;
		   cout<<endl;
		  cout<<"Switches:"<<endl;
		  cout<<"   -h"<<"   See the specific information for the programs."<<endl;
		   cout<<endl;
                  cout<<"Arguments:"<<endl;
		  cout<<"   file name"<<"   The sound flie includes various parameters and the file type is .cs229."<<endl;
		exit(1);
	}

        else {
      
	  if(strcmp(argv[1],"sndinfo")==0){
		  cout<<endl;
                cout<<"The program 'sndinfo' starts to run!! "<<endl;
                cout<<endl;
		  if(argc==2){
			   // standard inputi
                                
					 string filename_in;
					 int ii=0;
					 while(ii>-1){
					  cout<<"please  type file name below. Type ok to quit input."<<endl;
					  cin>>filename_in;
					  // if(strcmp(filename_in,"ok")==0) break;
					  if(filename_in=="ok") break;
					  fileNames_in.push_back(filename_in);
					  cout<<"You have typed a file name: "<< fileNames_in[ii]<<endl;
                       
					  ii = ii+1;
					 }
                   			                   		 
                             i_argc= ii;
                             numberOfSound = i_argc; 
							 const char * i_argv[numberOfSound-1];
                                
                                 sound allSound_in[i_argc];
                                 
                                   for(int i=0;i<numberOfSound;i++){
                                                
                                     cout<<"read file: "<<fileNames_in[i]<<endl;
                                     allSound_in[i] = sound(fileNames_in[i]);
 
                                   }
								   soundFileReader reader1;
                                 simpleDisplayer displayer1;
    
                        for(int i=0;i<numberOfSound;i++){
                         
                            reader1.readSoundFile(allSound_in[i]);
                            displayer1.display(allSound_in[i]);
                        }
                                                		
        

		  }
		  else{
         	  if(strcmp(argv[2],"-h")==0){
                           cout<<"Information for the program 'sndinfo'"<<endl;
                             cout<<endl;
			   cout<<"sndinfo [Switches] file_1 file_2 ... file_n"<<endl;
			   cout<<"   sndinfo   "<<"  This program reads all sound files passed as arguments, and for each one, displays the following."<<endl;
			    cout<<endl;
			   cout<<"Switches:"<<endl;
			   cout<<"   -h  "<<"  Print help (this message) and exit"<<endl;
                             cout<<endl;
                           cout<<"Arguments:"<<endl;
                           cout<<"   file_n  "<<"   File name, the sound flie includes various parameters and the file type is .cs229."<<endl;

			   exit(1);
		      }
	          else {
                                                        
                            i_argc=argc-2;
                            numberOfSound = i_argc;      
			 		 
                          const char * i_argv[numberOfSound-1];
                                 sound allSound[i_argc];
                                                                                            
                                                 for(int i=0;i<numberOfSound;i++){
                                                  
                                                       i_argv[i] = argv[i+2];
                                                    
                                                 }
                               
			       for(int i=0;i<numberOfSound;i++){
		                   filename = i_argv[i];
			     
                         fileNamesArr.push_back(filename);
	 			     cout<<"read file: "<<fileNamesArr[i]<<endl;
	  		         allSound[i] = sound(fileNamesArr[i]);
			
			       }
                              
                      soundFileReader reader1;
                      simpleDisplayer displayer1;
    
                        for(int i=0;i<numberOfSound;i++){
                                               
                           reader1.readSoundFile(allSound[i]);
                           displayer1.display(allSound[i]);
                         
                        
                        }
		      } //if -h
		  }
	  }
	  
	  else if(strcmp(argv[1],"sndcat")==0){
		  cout<<endl;
                cout<<"The program 'sndcat' starts to run!! "<<endl;
                cout<<endl;
		      if(strcmp(argv[2],"-h")==0){
        		       cout<<"Information for the program 'sndcat'"<<endl;
			     cout<<"   sndcat   "<<"  This program reads all sound files passed as arguments, and writes a single sound file that is concatenation of the inputs."<<endl;
			    cout<<" "<<endl;
                           cout<<"sndcat is used as below:"<<endl;
                            cout<<" "<<endl;

			   cout<<"sndcat [Switches] file_1 file_2 ... file_n"<<endl;
                           cout<<" "<<endl;

			   cout<<"Switches:"<<endl;
			   cout<<"  -o  file  "<<"  file : specify the output file name; if omitted, write to standard output"<<endl;
			   cout<<"  -h        "<<"  Print help (this message) and exit"<<endl;
			  // cout<<"  -w        "<<"  optionally for bonus points output in .wav format instead of .cs229 format"<<endl;
			   cout<<endl;

                           cout<<"Arguments:"<<endl;
              		   cout<<"   file_n  "<<"   File name, the sound flie includes various parameters and the file type is .cs229."<<endl;
			   exit(1);
		      }
			  else if(argc==2){
                		cout<<"   This program does not handle the standard input, please type the input file as arguments. Program Stop."<<endl;
				exit(1);
			  }
			  else if(argc>2){
				  if(strcmp(argv[2],"-o")==0 &&(argc==3||argc==4)) {			
                             
				         cout<<"   This program does not handle the standard input, please type the input file as arguments. Program Stop."<<endl;
				         exit(1);
				  }
				  else{
				   if(strcmp(argv[2],"-o")!=0){
                      				i_argc=argc-2;
                     				 numberOfSound = i_argc; 
					  const char * i_argv[numberOfSound-1];
                                           sound allSound[i_argc];

                                  	for(int i=0;i<numberOfSound;i++){
                                         
                                        	i_argv[i] = argv[i+2];
                                  	}

			              for(int i=0;i<numberOfSound;i++){
		                   		filename = i_argv[i];
			     
                          		fileNamesArr.push_back(filename);
				         cout<<"read file: "<<fileNamesArr[i]<<endl;
			            	 allSound[i] = sound(fileNamesArr[i]);
			
			              }
                   		   	soundFileReader reader1;
                      			simpleDisplayer displayer1;
    
                     			for(int i=0;i<numberOfSound;i++){
                                             
                         			reader1.readSoundFile(allSound[i]);
                         		//	displayer1.display(allSound[i]);
                        
                      			}
                      		       sound* sC=new sound();
						//when sndcat, call this
                       			soundCat cat1;
                       			cat1.cat(allSound, *sC,numberOfSound);
                            		sC->fileType=".cs229";
    
                      			 //without -o, call
                      			simpleDisplayer displayer2;
                        		displayer2.display(*sC);
				
				   }
				   else {
					  i_argc=argc-4;
                      				numberOfSound = i_argc; 
					  const char * i_argv[numberOfSound-1];
                                      		sound allSound[i_argc];

                                  	for(int i=0;i<numberOfSound;i++){
                                         
                                        	i_argv[i] = argv[i+4];
                                  	}

			          	for(int i=0;i<numberOfSound;i++){
		            	      		 filename = i_argv[i];
			     
                                	   	fileNamesArr.push_back(filename);
				        	cout<<"read file: "<<fileNamesArr[i]<<endl;
			           	 	allSound[i] = sound(fileNamesArr[i]);
			
			           	}
                       			 soundFileReader reader1;
                        		simpleDisplayer displayer1;
    
  			                     for(int i=0;i<numberOfSound;i++){
                                             
                        			 reader1.readSoundFile(allSound[i]);
                       				//  displayer1.display(allSound[i]);
                        
                       			}
                       				 sound* sC=new sound();
						//when sndcat, call this
                       				soundCat cat1;
                      				 cat1.cat(allSound, *sC,numberOfSound);
					   					 //with -o,call
                        			sC->fileName=argv[3];//"edit" should be changed into specified output name
   
					 //with -o
                        			FileDisplayer fileDisplayer1;
					        fileDisplayer1.display(*sC);
					 }// -o and c>

				  }//-o and c=3
					  					  
					  
		   } //argc>2
	  }
	  
	  else if(strcmp(argv[1],"sndmix")==0){
		  cout<<endl;
                cout<<"The program 'sndmix' starts to run!! "<<endl;
                cout<<endl;
		  //   if(strstr(argv[2],"-h")!=NULL){
		 
		    if(strcmp(argv[2],"-h")==0){
                           cout<<"Information for the program 'sndmix'"<<endl;
			   cout<<"   sndmix   "<<"  This program reads all sound files passed as arguments, and mixes them into a single sound file."<<endl;
			   cout<<"sndmix is used as below. Note that you have to follow the style, otherwise the program will stop."<<endl;
                             cout<<endl;

			   cout<<"sndmix [Switches] mult_1 file_1 mult_2 file_2...mult_n file_n"<<endl;
			    cout<<endl;

                           cout<<"Switches:"<<endl;
			   cout<<"   -h        "<<"  Print help (this message) and exit"<<endl;
			   cout<<"   -o  file  "<<"  specify the output file name; if omitted, write to standard output"<<endl;
                              cout<<endl;

			   cout<<"Arguments:"<<endl;
			   cout<<"   mult_n  "<<"   a real value between -10 and 10."<<endl; 
                           cout<<"   file_n  "<<"   File name, the sound flie includes various parameters and the file type is .cs229."<<endl; 
			   exit(1);
		     }
			 else if(argc==2||argc==3){
                		cout<<"   This program does not handle the standard input, please type the input file as arguments. Program Stop."<<endl;
				exit(1);
			 }
			 else if(argc>3){
				  if((strcmp(argv[2],"-o")==0)&&(argc==4||argc==5)) {			
                             
				         cout<<"   This program does not handle the standard input, please type the input file as arguments. Program Stop."<<endl;
				         exit(1);
				  }
				  else {
					  if(strcmp(argv[2],"-o")!=0){
						  if((argc-2)%2!=0){
							  cout<<"Number of mult does not match with number of sound"<<endl;
							  cout<<"   Please type the mult_n value with the input file. They should match with each other. Program Stop."<<endl;
							  exit(1);
						  }
						    int numberOfMult,numberOfSoundForMix;
							numberOfMult=int((float(argc-2))/2.0);//dd change numberOfMult according to command line
							numberOfSoundForMix=int((float(argc-2))/2.0); //dd change numberOfSoundForMix according to command line
						    float multArr[numberOfMult];
						    std::vector<std::string> MultComandArr;

						    for(int i=0;i<numberOfSoundForMix;i++){
						      MultComandArr.push_back(argv[i*2+2]);
						//	  cout<<"read mult:"<<" ' "<<i+1<<" ' "<<MultComandArr[i]<<endl;//test
						    }
    
						
					
								for(int i=0;i<numberOfMult;i++){
								 float value = atof(MultComandArr[i].c_str());
								  if(value>10 || value<-10){
									cout<<"The value for multiplication is greater than 10 or less than -10. It is illegal."<<endl;
								   exit(1);
								  }
							      multArr[i]=value;
							//	  cout<<"value:  "<<multArr[i]<<endl;
								}
								 
								std::vector<std::string> fileNamesArrMix;
								sound allSoundMix[numberOfSoundForMix];
				
						 // *** add strings to the array ***
								 for(int i=0;i<numberOfSoundForMix;i++){
									fileNamesArrMix.push_back(argv[i*2+3]);
							//		cout<<"read file: "<<fileNamesArrMix[i]<<endl;
									allSoundMix[i]=sound(fileNamesArrMix[i]);
								 
								 }
									 soundFileReader reader1;
    								        simpleDisplayer displayer1;			
		
								 for(int i=0;i<numberOfSoundForMix;i++){
									 reader1.readSoundFile(allSoundMix[i]);
									// displayer1.display(allSoundMix[i]);
								 }
    
                            //multArr array and fileNamesArrMix array are one-to-one
								 soundMix mix;
								 sound* sC1=new sound();
								 mix.mix(allSoundMix,*sC1, numberOfSoundForMix, multArr);
								 sC1->fileType=".cs229";
                           //without -o, call
								 simpleDisplayer displayer2;
							         displayer2.display(*sC1);
				
					  }//if without -o
					  else {
						  if((argc-4)%2!=0){
							  cout<<"Number of mult does not match with number of sound"<<endl;
							  cout<<"Please type the mult_n value with the input file. They should match with each other. Program Stop."<<endl;
							  exit(1);
						  }
						    int numberOfMult,numberOfSoundForMix;
							numberOfMult=int((float(argc-4))/2.0);//dd change numberOfMult according to command line
							numberOfSoundForMix=int((float(argc-4))/2.0); //dd change numberOfSoundForMix according to command line
						    float multArr[numberOfMult];
						    std::vector<std::string> MultComandArr;

						    for(int i=0;i<numberOfSoundForMix;i++){
						      MultComandArr.push_back(argv[i*2+4]);
						//	  cout<<"read mult:"<<" ' "<<i+1<<" ' "<<MultComandArr[i]<<endl;//test
						    }
    				
								for(int i=0;i<numberOfMult;i++){
								 float value = atof(MultComandArr[i].c_str());
								  if(value>10 || value<-10){
									cout<<"The value for multiplication is greater than 10 or less than -10. It is illegal."<<endl;
								   exit(1);
								  }
							      multArr[i]=value;
						//		  cout<<"value:  "<<multArr[i]<<endl;
								}
								 
								std::vector<std::string> fileNamesArrMix;
								sound allSoundMix[numberOfSoundForMix];
				
						 // *** add strings to the array ***
								 for(int i=0;i<numberOfSoundForMix;i++){
									fileNamesArrMix.push_back(argv[i*2+5]);
							//		cout<<"read file: "<<fileNamesArrMix[i]<<endl;
									allSoundMix[i]=sound(fileNamesArrMix[i]);
								 
								 }
									 soundFileReader reader1;
    									simpleDisplayer displayer1;					
								 for(int i=0;i<numberOfSoundForMix;i++){
									 reader1.readSoundFile(allSoundMix[i]);
							//		 displayer1.display(allSoundMix[i]);
								 }
    
                            //multArr array and fileNamesArrMix array are one-to-one
								 soundMix mix;
								 sound* sC1=new sound();
								 mix.mix(allSoundMix,*sC1, numberOfSoundForMix, multArr);
								 sC1->fileName=argv[3];
								 FileDisplayer fileDisplayer1;
								 fileDisplayer1.display(*sC1);

					   }// with -o
				  } //argc 		       
			}//argc>3	        
	  }
	  else if(strcmp(argv[1],"sndgen")==0){
		cout<<endl;
		cout<<"The program 'sndgen' starts to run!! "<<endl;
		cout<<endl;
		   if(strcmp(argv[2],"-h")==0){
                           cout<<"Information for the program 'sndgen'"<<endl;
			   cout<<"   sndgen    "<<"  This program produces a sound of a specified frequency and wavefrom using a simple ADSR envelope."<<endl;
			   cout<<"sndgen is used as below. "<<endl;
                             cout<<endl;

			   cout<<"sndgen [Switches] "<<endl;
			    cout<<endl;

                           cout<<"Switches:"<<endl;
			   cout<<"   -h        "<<"  Print help (this message) and exit"<<endl;
			   cout<<"   -o  file  "<<"  specify the output file name; if omitted, write to standard output"<<endl;
			   cout<<"   --bits n  "<<"  use a bit depth of n"<<endl;
			   cout<<"   --sr n    "<<"  use a sample rate of n"<<endl;
			   cout<<"   -f r      "<<"  use a frequency of r Hz"<<endl;
			   cout<<"   -t r      "<<"  total duration of r seconds"<<endl;
			   cout<<"   -v p      "<<"  Peak volume. 0 <= p <= 1"<<endl;
			   cout<<"   -a r      "<<"  attack time of r seconds"<<endl;
			   cout<<"   -d r      "<<"  decay time of r seconds"<<endl;
			   cout<<"   -s p      "<<"  sustain volume. 0 <= p <= 1"<<endl;
			   cout<<"   -r r      "<<"  release time of r seconds"<<endl;
			   cout<<"   --sine    "<<"  generate a sine wave"<<endl;
			   cout<<"   --triangle"<<"  generate a triangle wave"<<endl;
			   cout<<"   --sawtooth"<<"  generate a sawtooth wave"<<endl;
			   cout<<"   --pulse   "<<"  generate a pulse wave"<<endl;
			   cout<<"   --pf p    "<<"  Fraction of the time the pulse wave is ''up'' "<<endl;
                           cout<<endl;			   
			   exit(1);
		   }
		   else{
                      sound* sCgen=new sound();

			 sinewave sinewaveGenerator;
  			 ADSRgenerator amplitudeGen;
   			 triangleWave triangleWaveGenerator;
    		         sawtoothWave  sawtoothWaveGen;
			 pulseWave pulseWaveGen;
                       
                                            
 			string givenName;
                         int bits=0,frequency=0;
   			 double sr=0, fraction=0;
   			 double duration=0;
    			 double amplitude=1;//dd change
    			double peakL,sustL;
    			double attackTime;
    			double decayTime;
    			double releaseTime;  
			int flag_sine=0,flag_tri=0,flag_saw=0,flag_pulse=0; 
                        int flag_output=0 ;
 											                      
                                i_argc=argc-2;
                     		numberOfSound = i_argc; 
		 		string stringValue;
                                int   jj=0;
			
				   while(jj<argc-2){
			         	   stringValue=argv[jj+2];
                                          
			 		 switch (hashit(stringValue)) {
	          			   case ff: 
 						  if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 frequency =atoi(argv[jj+3]);
                                               //  cout<<"test "<<argv[jj+3]<<" "<<frequency<<endl;
                                                   jj=jj+2;
													
						 
					         goto LOOP;		
					   case tt:
                                                 if(jj+3>argc) { 								                                        cout<<argv[jj+2]<<" need a input value"<<endl;
					   	   cout<<"Program stop"<<endl;
     						   exit(1);
                                                 } 
                                                 duration=atof(argv[jj+3]);
   						// cout<<"test "<<argv[jj+3]<<" "<<duration<<endl;
	    					   jj=jj+2;	 
      						   goto LOOP;
                         		   case vv:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 peakL =atof(argv[jj+3]);
                                                // cout<<"test "<<argv[jj+3]<<" "<<peakL<<endl;
                                                   jj=jj+2;
                                    		  
                                    		  goto LOOP;
				           case aa:
  			                         if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 attackTime =atof(argv[jj+3]);
                                                // cout<<"test "<<argv[jj+3]<<" "<<attackTime<<endl;
                                                   jj=jj+2;
                               		    	 goto LOOP;
       					   case dd:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 decayTime =atof(argv[jj+3]);
                                                // cout<<"test "<<argv[jj+3]<<" "<<decayTime<<endl;
                                                   jj=jj+2;
							goto LOOP;
					   case ss:
 						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 sustL =atof(argv[jj+3]);
                                                 //cout<<"test "<<argv[jj+3]<<" "<<sustL<<endl;
                                                   jj=jj+2;
							goto LOOP; 
		               		   case rr:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 releaseTime =atof(argv[jj+3]);
                                               //  cout<<"test "<<argv[jj+3]<<" "<<releaseTime<<endl;
                                                   jj=jj+2;
							goto LOOP;
					   case sine:

						flag_sine=1;
                                             //    cout<<"test "<<argv[jj+3]<<" "<<flag_sine<<endl;
                                                   jj=jj+1;

							goto LOOP;
			  		   case tri:
						flag_tri=1;
					//	cout<<"test "<<argv[jj+2]<<" "<<flag_tri<<endl;
						 jj=jj+1;
			      			goto LOOP;
  				  	   case saw:
						flag_saw=1;
                                          //      cout<<"test "<<argv[jj+2]<<" "<<flag_saw<<endl;
                                                 jj=jj+1;
						goto LOOP;
					   case pulse:
						flag_pulse=1;
                                            //    cout<<"test "<<argv[jj+2]<<" "<<flag_pulse<<endl;
                                                 jj=jj+1;
					 	goto LOOP;
					   case pf_in:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 fraction =atof(argv[jj+3]);
                                              //   cout<<"test "<<argv[jj+3]<<" "<<fraction<<endl;
                                                   jj=jj+2;
						goto LOOP;
		  			   case bits_in:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 bits =atoi(argv[jj+3]);
                                                // cout<<"test "<<argv[jj+3]<<" "<<bits<<endl;
                                                   jj=jj+2;
						goto LOOP;
					   case sr_in:
						if(jj+3>argc) {                                                                                                        cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 sr =atoi(argv[jj+3]);
                                                // cout<<"test "<<argv[jj+3]<<" "<<sr<<endl;
                                                   jj=jj+2;
						goto LOOP;
 					   case oo:
						if(jj+3>argc) {  
                                                   cout<<argv[jj+2]<<" need a input value"<<endl;
                                                   cout<<"Program stop"<<endl;
                                                   exit(1);
                                                 }
                                                 givenName = argv[jj+3]; 
					         flag_output=1;
                                                // cout<<"test "<<argv[jj+3]<<" "<<givenName<<endl;
                                                   jj=jj+2;
						 goto LOOP;
					   default :
						cout<<"The switch you input '"<<argv[jj+2]<<"' does not exist"<<endl;
                                                cout<<"Program stop."<<endl;		
                  				exit(1);				
						
					}//switch
                               	LOOP: cout << endl;

				  }//while
                            sCgen->length=duration;
			    sCgen->sampleRate=sr;
    			    sCgen->samples=(int)(duration*sr);
			    sCgen->bitDepth=bits;
			    sCgen->channels=1;
			    sCgen->fileType=".cs229 file";
			    sCgen->fileName=givenName;
			    sCgen->data= new double*[sCgen->samples];
			    for(int i = 0; i < sCgen->samples; ++i) {
			        sCgen->data[i] = new double[sCgen->channels];
			    }
                             // double valueArr= new double*[sCgen->samples];
                            //for(int i = 0; i < sCgen->samples; ++i) {
                              //  sCgen->data[i] = new double[sCgen->channels];
                            //}
                           

                        

			string inn;
 			
			                 cout<<"Read parameters done..."<<endl;
					cout<<endl;
			 //--------------------
			  int n_samples = int (double(sr)*duration);
				double value[n_samples];
			    double eachSample=1.0/double(sr);
   			  double sustainTime=duration-attackTime-decayTime-releaseTime;
    			if(peakL>1 || peakL<0 || sustL>1 || sustL<0){
        			cout<<"Peak Volume or Sustain Volume is not in [0,1] range"<<endl;
        			exit(1);
    			}
   		 	if(duration<releaseTime){
        			cout<<"No sound should be produced if the duration t is less than the release time"<<endl;
        			exit(1);
    			}
  		  	if(sustainTime<0){ //sustain stage is less than zero time, shorten release time

        			releaseTime=releaseTime+sustainTime;
				sustainTime=0;
		          if(releaseTime<0){//release stage is less than zero time, shorten attack time
            			double newAttackTime=attackTime+releaseTime;
            			double newPeakL;
            			double oldPeakL=peakL;
            			newPeakL=(newAttackTime/attackTime)*peakL;
            			attackTime=newAttackTime;

            			double newSustainL=(sustL*newPeakL)/peakL;
            			peakL=newPeakL;
            			double oldSustainL=sustL;
            			sustL=newSustainL;

            			releaseTime=0;
            		  	if(attackTime<0){

                			double newDecayTime=decayTime+attackTime;
                			newSustainL=((oldPeakL-oldSustainL)*(decayTime-newDecayTime)/decayTime)+oldSustainL;//sustL;
                			sustL=newSustainL;
 				//	cout<<oldPeakL<<" "<<oldSustainL<<" "<<decayTime<<" "<<newDecayTime<<" "<< sustL<<endl;
                			attackTime=0;
					decayTime = newDecayTime;
					peakL = oldPeakL;

                			if(newDecayTime<0){
                    			cout<<"No time for ADSR envelope. No sound is produced"<<endl;
                    			exit(1);
                			}

            		        }	
        		   }//releasetime<0
    		      }//sus<0

			 //------------------	

                        if(flag_sine==1) {
			//	cout<<"eachSample"<<eachSample<<endl;
                        	cout<<"Sine wave is generated..."<<endl;
				for(int i = 0; i < n_samples + 1; i++){
                                double time=i*eachSample;
                                if(time>duration){break;}
                                amplitude=amplitudeGen.calcA(bits, peakL, sustL, time,  duration, attackTime, decayTime, releaseTime);
		              // cout<<time<<" "<<amplitude<<endl;	
                                 value[i]=amplitude*sinewaveGenerator.value(time, duration,frequency);               
                                 

             			   sCgen->data[i] = &value[i];
            		
		          // if(i>1)   cout<<"time: "<<int(*(sCgen->data[i]))<<" "<<int(*sCgen->data[i-1])<<endl;	
                                }
//cin>>inn;
 
    			}
			else if(flag_tri==1){
				cout<<"Triangle Wave data is generated..."<<endl;
   				 for(int i = 0; i < n_samples + 1; i++){
        
        				double time=i*eachSample;
       
       				 	if(time>duration){break;}
        				amplitude=amplitudeGen.calcA(bits, peakL, sustL, time,  duration, attackTime, decayTime, releaseTime);
       
        			   value[i]=amplitude*triangleWaveGenerator.value(time, duration,frequency);
			          // for(int i = 0; i < sCgen->samples; ++i) {
            				sCgen->data[i] = &value[i];
        			  // }


				 } 
			}
			else if(flag_saw==1){
				 cout<<"sawtoothWave data is generated ..."<<endl;
				    for(int i = 0; i < n_samples + 1; i++){
        
        			     	double time=i*eachSample;
        
        				if(time>duration){break;}
      					 amplitude=amplitudeGen.calcA(bits, peakL, sustL, time,  duration, attackTime, decayTime, releaseTime);
        
       				       value[i]= amplitude*sawtoothWaveGen.value(time, duration,frequency);
				     //   for(int i = 0; i < sCgen->samples; ++i) {
          				  sCgen->data[i] = &value[i];
        			    //	}


    				     }

			}
			else if(flag_pulse==1){
                          cout<<"pulsewave data is generated..."<<endl;
			    for(int i = 0; i < n_samples + 1; i++){
        
        			double time=i*eachSample;
        
        			if(time>duration){break;}
        			amplitude=amplitudeGen.calcA(bits, peakL, sustL, time,  duration, attackTime, decayTime, releaseTime);
        
        			value[i]= amplitude*pulseWaveGen.pulseValue(time, duration,frequency,fraction);
        		//	for(int i = 0; i < sCgen->samples; ++i) {
            				sCgen->data[i] = &value[i];
        		//	}

    			     }


			}// flag
                               
                                  
                        
			if(flag_output==1){
				FileDisplayer fileDisplayer_out;		
				fileDisplayer_out.display(*sCgen);
			}
			else if(flag_output==0){
                                        cout<<"Standard output"<<endl;
					cout<<endl;
					simpleDisplayer displayer2;
					 displayer2.display(*sCgen);
				//	for(int i = 0; i < n_samples + 1; i++){

                                        //cout<<"value: "<<int(value[i])<<endl;
				//	}
                        }             
		   }// no -h
	  } //sndgen
	  else {
          cout<<"The input program is not available in this code. Please use -h to see the information."<<endl;
		  exit(1);
	  }
  } //argc >1
  
 
  cout<<"Program finished"<<endl;
   
  
   
}




