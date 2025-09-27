all: 5.4

run: 
	./5.4

clean: 
	rm -f *.o

analysis.o: analysis.cc analysis.h
	g++ -c -Wall -Werror analysis.cc

5.4.o: 5.4.cc analysis.h
	g++ -c -Wall -Werror 5.4.cc

5.4: 5.4.o analysis.o
	g++ -o 5.4 5.4.o analysis.o