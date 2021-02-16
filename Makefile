Battleship: main.o
	g++ -std=c++11 -g -Wall main.o -o Battleship

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o Battleship
