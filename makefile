all: Converter.o main.cpp
	g++ Converter.o main.cpp

Converter.o: Converter.cpp Converter.h
	g++ -c Converter.cpp -o Converter.o

clean:
	rm *.o *.out
