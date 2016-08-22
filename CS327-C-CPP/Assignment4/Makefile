#this is make file
all: main 
main: main.o soundFile.o Displayer.o SimpleDisplayer.o FileDisplayer.o soundCat.o soundMix.o waveform.o sinewave.o triangleWave.o sawtoothWave.o ADSRgenerator.o pulseWave.o
	g++ -o main main.o soundFile.o Displayer.o SimpleDisplayer.o FileDisplayer.o soundCat.o soundMix.o waveform.o sinewave.o triangleWave.o sawtoothWave.o ADSRgenerator.o pulseWave.o
soundFile.o: soundFile.cpp soundFile.hpp
	g++ -c soundFile.cpp
Displayer.o: Displayer.cpp Displayer.hpp soundFile.hpp
	g++ -c Displayer.cpp 
SimpleDisplayer.o: SimpleDisplayer.cpp SimpleDisplayer.hpp soundFile.hpp Displayer.hpp
	g++ -c SimpleDisplayer.cpp
FileDisplayer.o: FileDisplayer.cpp FileDisplayer.hpp soundFile.hpp Displayer.hpp
	g++ -c FileDisplayer.cpp
soundCat.o: soundCat.cpp  soundCat.hpp SimpleDisplayer.hpp soundFile.hpp Displayer.hpp
	g++ -c soundCat.cpp
soundMix.o: soundMix.cpp  soundMix.hpp soundFile.hpp
	g++ -c soundMix.cpp
ADSRgenerator.o: ADSRgenerator.cpp  ADSRgenerator.hpp soundFile.hpp
	g++ -c ADSRgenerator.cpp
waveform.o: waveform.cpp  waveform.hpp soundFile.hpp 
	g++ -c waveform.cpp
sinewave.o: sinewave.cpp sinewave.hpp soundFile.hpp waveform.hpp
	g++ -c sinewave.cpp
triangleWave.o: triangleWave.cpp triangleWave.hpp soundFile.hpp waveform.hpp
	g++ -c triangleWave.cpp
sawtoothWave.o: sawtoothWave.cpp sawtoothWave.hpp soundFile.hpp waveform.hpp
	g++ -c sawtoothWave.cpp
pulseWave.o: pulseWave.cpp pulseWave.hpp soundFile.hpp waveform.hpp
	g++ -c pulseWave.cpp
main.o: main.cpp  soundFile.hpp Displayer.hpp SimpleDisplayer.hpp FileDisplayer.hpp soundCat.hpp soundMix.hpp sinewave.hpp triangleWave.hpp sawtoothWave.hpp pulseWave.hpp ADSRgenerator.hpp
	g++ -c main.cpp
clean:
	rm -f *.o main
zipfile:
	 zip Cs327_Yiran_Xu_HW4.zip *.cpp *.hpp Makefile YiranXu_UML.pdf README.txt
unzipfile:
	unzip Cs327_Yiran_Xu_HW4.zip
 
