#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include <memory>
#include <math.h>


#include <cstdint>
#include <iostream>

using namespace project;

int main(){

	static const int width=800;
	static const int height =800;

	Bitmap b(width,height);
	b.setPixel(300, 400, 255, 255, 255);

	double min=999999;
	double max=-999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}); //iterations:number of pixels
	unique_ptr<int[]> fractal(new int[width*height]{0}); //pixel:iterations



	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			double xFractal=(x-width/2-200)*2.0/height; 		//centered coodinate (-300,300)
			double yFractal=(y-height/2)*2.0/height; 	// ditto



			int iterations=Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y*width+x]=iterations; 		//store the number of iterations for each pixel;

			if(iterations!=Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}

		}
	}


	int total=0;

	for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++){ 		//count total number of pixels per iteration
		total+=histogram[i];
	}

		for(int x=0;x<width;x++){
			for(int y=0;y<height;y++){
				uint8_t red=0;
				uint8_t green=0;
				uint8_t blue=0;
				
				int iterations=fractal[y*width+x]; 		//store the number of iterations for each pixel;

	
						if(iterations!=Mandelbrot::MAX_ITERATIONS){

						double hue=0.0;

						for(int i=0;i<=iterations;i++){ 		//hue is based on how common that pixel is
							hue+=(double)histogram[i]/total;
						}

						uint8_t red=pow(255,hue);
						uint8_t green=pow(255,hue);
						uint8_t blue=pow(255,hue);

						b.setPixel(x,y,red,green,blue);
				}
			}
		}




	b.write("bitmap.bmp");
	std::cout<<"Bitmap generated.\n";
	

}
