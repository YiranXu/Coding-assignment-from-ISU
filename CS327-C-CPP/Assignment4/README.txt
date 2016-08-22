Please notice:  I talked to Dr. James Lathrop about waveform, and he said all the wave form should be shifted up by 1 to a range of [0,2] instead of [-1,1] before multiplying amplitude. 

1.main.cpp:
Create instances of sound, soundFileReader, simpleDisplayer, FileDisplayer, soundCat, soundMix and call corresponding methods. 
sengen part is to create a new sound according to command line arguments.
I created instances of a new sound, ADSRgenerator, sinewave, triangleWave, sawtoothWave, pulseWave. I updated information of member field of the new sound. 

If duration of the sound is shorter than the total time of ADSR envelop (sum of attack, decay, sustain and release time), then sustain time is shortened.

If sustainTime is less than 0, release time will be shortened. 

If release time is less than 0, attack time is shortened. In this case, there would be a new peak volume and sustain volume. Assume we keep the proportion of peak volume and sustain volume unchanged,  

if attackTime is shortened to below 0,the starting amplitude of decay time is initialized peak Volume so that the final amplitude of this stage will be higher than the sustain volume. 

The new sustain volume is obtained from similar triangle method. 

2.soundFile.cpp
Generate a sound class and a soundFileReader class.
Sound is the object that the whole program is dealing with. Sound has members necessary for a cs229 sound file format such as fileName, samples, sampleRate and bitDepth.

SoundFileReader is to read a sound with a file name (passed in command line by user) and update all the member field in the sound. 

3.Display is an abstract class for displaying data.

4.SimpleDisplayer is a derived class from Display to display information of sound files to standard output.

5.FileDisplayer is a derived class from Display to display information of sound files to specified file. It is used for sndcat and sndmix programs to write a new single sound file.

6.soundCat is a class called soundCat. The purpose of this class is to concatenate all the files passed as arguments (stored in a sound array) and put the concatenated sound in a new sound. 
Notice: To concatenate, number of channels and sample rate in all the sound should be the same. 
If bit depth is not consistent, the bit depth for the new sound is the max bit depth among all the passed sound. 
Number of samples for the new sound is the sum of samples for all sound files. 
Length is also the sum of length for all sound files.

7.soundMix is a class called soundMix. The purpose of this class is to multiply data in nth sound file with nth multiplication, and add the results together to form a new sound. 
Similarly as soundCat, number of channels and sample rate needs to be consistent among all the sound files, otherwise, mix fails.
Bit depth is still the max bit depth among all the passed sound.
Length is the longest length among all the passed sound.

8.waveform is an abstract class to generate value for sine wave, triangle wave, sawtooth wave and pulse wave.

Notice:  when implementing value method to generate value for waveform, all the wave form is shifted up by 1 to a range of [0,2] instead of [-1,1] according to the professor. 

9. sinewave is a derived class from waveform to generate value of sine wave.

10. triangleWave is a derived class from waveform to generate value of triangle wave.

11. sawtoothWave is a derived class from waveform to generate value of sawtooth wave.

12. pulseWave a derived class from waveform to generate value of pulse wave.
Notice: I did not implement the method derived from waveform but I made a new method for this class because I need an extra parameter(Fraction of the time the pulse wave is “up”) passed as parameter.

13.ADSRgenerator is a class to get value for amplitude according to ADSR envelope so that we could multiply the amplitude to waveform to generate sound.
The method I used to calculate amplitude is from similar triangle.

TEST:
The programs are valid in the code as shown below:

./main
./main -h
./main sndinfo -h
./main sndinfo
./main sndinfo -h file_1 file_2 ... file_n
./main sndinfo file_1 file_2 ... file_n

./main sndcat  -h
./main sndcat  -h file_1 file_2 ... file_n
./main sndcat  -o file file_1 file_2 ... file_n 
./main sndcat  file_1 file_2 ... file_n

./main sndmix  -h
./main sndmix  -h file_1 file_2 ... file_n
./main sndmix  -o file multi_1 file_1 multi_2 file_2 ... multi_n file_n
./main sndmix  multi_1 file_1 multi_2 file_2 ... multi_n file_n

./main sndgen  -h
./main sndgen  -h -a num -t num... 
./main sndgen  -o file -a num... 
./main sndgen  --sine -o file -a num...


The programs will show errors as shown below:

./main sndcat             // no switch or argument
./main sndcat  -o         // no file
 
./main sndcat  -o file_1 file_2 ... file_n         //no output file name  

./main sndmix                                          // no switch or argument
./main sndmix  -o multi_1 file_1 multi_2 file_2 ... multi_n file_n  //no output file name
./main sndmix  -o file multi_1 file_1 multi_2         // missing file_2 
./main sndmix multi_1 file_1  file_2                  // missing multi_2

./main sndgen                                    // no switch or argument
./main sndgen  -o  -a ...                        //no output file name
./main sndgen  --sine --pulse -o file -a num...   // should not have two waves
