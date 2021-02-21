Battleship: main.o Executive.o Ships.o Board.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Battleship

main.o: main.cpp Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Ships.cpp Ships.h Board.cpp Board.h
		g++ -g -std=c++11 -Wall -c Executive.cpp

Ships.o: Ships.cpp Ships.h
			g++ -std=c++11 -g -Wall -c Ships.cpp

Board.o: Board.cpp Board.h
				g++ -std=c++11 -g -Wall -c Board.cpp

clean:
	rm *.o Battleship
