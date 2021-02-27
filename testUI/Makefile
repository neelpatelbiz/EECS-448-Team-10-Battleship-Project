test.out: test.o
	g++ -std=c++11 -g -Wall test.o -lX11 -lm -lpthread -o test.out

test.o: test.cpp 
	#g++ test.cpp -lm -lpthread -lX11
	g++ -std=c++11 -g -Wall -c test.cpp

clean: 
	rm *.o *.out test.out
