#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"


#include <cstdint>
#include <iostream>

using namespace project;

int main(){

	static const int width=600;
	static const int height =800;

	Bitmap b(600,800);
	b.setPixel(300, 400, 255, 255, 255);

	double min=999999;
	double max=-999999;



	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			double xFractal=(x-width/2)*2.0/width;
			double yFractal=(y-height/2)*2.0/height;

			int iterations=Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t red = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);


			b.setPixel(x,y,red,red,red);

			if(red<min) min=red;
			if(red>max) max=red;



		}
	}

	
	std::cout<<min<<", "<<max<<endl;


	b.write("bitmap.bmp");





	std::cout<<"Bitmap generated.\n";
	

}
