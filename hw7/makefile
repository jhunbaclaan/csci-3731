all: 8.1

run:
	./8.1

clean:
	rm -f *.o 8.1

imageMaker.o: imageMaker.cc imageMaker.h
	g++ -c -Wall -Werror imageMaker.cc

8.1.o: 8.1.cc imageMaker.h
	g++ -c -Wall -Werror 8.1.cc

8.1: 8.1.o imageMaker.o
	g++ -o 8.1 8.1.o imageMaker.o