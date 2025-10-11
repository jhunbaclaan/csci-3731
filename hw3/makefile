all: 6.2

clean:
	rm -f *.o

mandelbrot.o: mandelbrot.cc converge.h
	g++ -c -Wall -Werror mandelbrot.cc

4.3.o: 4.3.cc converge.h
	g++ -c -Wall -Werror 4.3.cc

4.3: 4.3.o mandelbrot.o
	g++ -o 4.3 4.3.o mandelbrot.o