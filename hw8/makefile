all: 9.3

run:
	./9.3

clean:
	rm -f *.o 9.3

Exercise.o: Exercise.cc Exercise.h Book.h
	g++ -c -Wall -Werror Exercise.cc

Book.o: Book.cc Book.h Exercise.h
	g++ -c -Wall -Werror Book.cc

9.3.o: 9.3.cc Book.h Exercise.h
	g++ -c -Wall -Werror 9.3.cc

9.3: 9.3.o Book.o Exercise.o
	g++ -o 9.3 9.3.o Book.o Exercise.o
