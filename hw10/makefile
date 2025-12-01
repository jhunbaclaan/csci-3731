CXXFLAGS = -Wall -Werror -std=c++11

all: 11.2

run:
	./11.2

clean:
	rm -f *.o

TextReader.o: TextReader.cc TextReader.h Pattern.h
	g++ $(CXXFLAGS) -c TextReader.cc

Pattern.o: Pattern.cc Pattern.h
	g++ $(CXXFLAGS) -c Pattern.cc

11.2.o: 11.2.cc TextReader.h Pattern.h
	g++ $(CXXFLAGS) -c 11.2.cc

11.2: 11.2.o TextReader.o Pattern.o
	g++ -o 11.2 11.2.o TextReader.o Pattern.o
