all: 3.3

clean:
	rm -f *.o

mandelbrot.o: mandelbrot.cc converge.h
	g++ -c -Wall -Werror mandelbrot.cc

3.3.o: 3.3.cc converge.h
	g++ -c -Wall -Werror 3.3.cc

3.3: 3.3.o mandelbrot.o
	g++ -o 3.3 3.3.o mandelbrot.o