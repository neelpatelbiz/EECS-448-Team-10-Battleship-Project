Battleship: main.o Executive.o Ships.o Board.o Ai.o MedAiTree.o Node.o
	g++ -std=gnu++11 -g -Wall main.o Executive.o Ships.o Board.o Ai.o MedAiTree.o Node.o -lX11 -lm -lpthread -o Battleship

main.o: main.cpp Executive.cpp Executive.h Ai.h
	g++ -std=gnu++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Ships.cpp Ships.h Board.cpp Board.h
	g++ -std=gnu++11 -g -Wall -c Executive.cpp

Ships.o: Ships.cpp Ships.h
	g++ -std=gnu++11 -g -Wall -c Ships.cpp

Board.o: Board.cpp Board.h
	g++ -std=gnu++11 -g -Wall -c Board.cpp

Ai.o: Ai.cpp Ai.h MedAiTree.h
	g++ -std=gnu++11 -g -Wall -c Ai.cpp

MedAiTree.o: MedAiTree.cpp MedAiTree.h Node.h Board.h
	g++ -std=gnu++11 -g -Wall -c MedAiTree.cpp

Node.o: Node.cpp Node.h
	g++ -std=gnu++11 -g -Wall -c Node.cpp

clean:
	rm *.o Battleship
