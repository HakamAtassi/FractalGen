#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include <memory>
#include <math.h>


#include <cstdint>
#include <iostream>

using namespace project;

int main(){

	static const int width=600;
	static const int height =800;

	Bitmap b(width,height);

	double min=999999;
	double max=-999999;

	ZoomList zoomList(width,height);
	zoomList.add(Zoom(width/2,height/2,4.0/width));
	zoomList.add(Zoom(295,height-190,0.5));

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}); //iterations:number of pixels
	unique_ptr<int[]> fractal(new int[width*height]{0}); //pixel:iterations



	for(int y=0;y<width;y++){
		for(int x=0;x<height;x++){
	
			std::pair<double,double> coords=zoomList.doZoom(x,y);


			int iterations=Mandelbrot::getIterations(coords.first,coords.second);

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
