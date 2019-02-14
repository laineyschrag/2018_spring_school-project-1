lab1: main.o Executive.o Gamer.o
	g++ -std=c++11 -g -Wall main.o Executive.o Gamer.o -o lab1

main.o: main.cpp Executive.h Gamer.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Gamer.o: Gamer.cpp Gamer.h
	g++ -std=c++11 -g -Wall -c Gamer.cpp

clean: 
	rm *.o lab1
