Battleship: main.o Executive.o Bot.o Board.o
	g++ -std=c++11 -g -Wall main.o Executive.o Bot.o Board.o -lX11 -lm -lpthread -o Battleship

main.o: main.cpp Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Ships.cpp Ships.h Board.cpp Board.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Bot.o: Bot.cpp Bot.h
	g++ -std=c++11 -g -Wall -c Bot.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -g -Wall -c Board.cpp

clean:
	rm *.o Battleship
