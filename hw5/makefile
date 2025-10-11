all: 6.2

make run:
	./6.2

make clean:
	rm -f *.o

mandelbrot.o: mandelbrot.cc mandelbrot.h
	g++ -c -Wall -Werror mandelbrot.cc

6.2.o: 6.2.cc mandelbrot.h
	g++ -c -Wall -Werror 6.2.cc

6.2: 6.2.o mandelbrot.o
	g++ -o 6.2 6.2.o mandelbrot.o