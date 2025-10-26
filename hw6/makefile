all: 7.1

run:
	./7.1

clean:
	rm -f *.o

images.o: images.cc images.h
	g++ -c -Wall -Werror -I/opt/homebrew/opt/jpeg/include images.cc

7.1.o: 7.1.cc images.h
	g++ -c -Wall -Werror -I/opt/homebrew/opt/jpeg/include 7.1.cc

7.1: 7.1.o images.o
	g++ -o 7.1 7.1.o images.o -L/opt/homebrew/opt/jpeg/lib -ljpeg