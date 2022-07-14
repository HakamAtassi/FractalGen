fractalGen: Bitmap.o FractalCreator.o Mandelbrot.o ZoomList.o RGB.o main.o
	g++ Bitmap.o FractalCreator.o Mandelbrot.o ZoomList.o RGB.o main.o -o fractalGen

Bitmap.o: Bitmap.cpp
	g++ -c Bitmap.cpp

FractalCreator.o: FractalCreator.cpp
	g++ -c FractalCreator.cpp

Mandelbrot.o: Mandelbrot.cpp
	g++ -c Mandelbrot.cpp

ZoomList.o: ZoomList.cpp
	g++ -c ZoomList.cpp

RGB.o: RGB.cpp
	g++ -c RGB.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o fractalGen

run: fractalGen
	./fractalGen
