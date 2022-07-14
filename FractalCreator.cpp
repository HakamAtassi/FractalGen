#include "FractalCreator.h"	
#include "Mandelbrot.h"
#include <math.h>
#include <iostream>
using namespace project;




FractalCreator::FractalCreator(int width, int height):width(width),height(height),
histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),fractal(new int[width*height]{0}),
bitmap(width,height),zoomList(width,height)
{
	std::cout<<"width: "<<width<<"\n";
	std::cout<<"height: "<<height<<"\n";
	zoomList.add(Zoom(width/2,height/2,4.0/width));
}

FractalCreator::~FractalCreator(){

} 

void FractalCreator::calculateIterations(){
	std::cout<<"Calculate Iterations\n\n";

	for(int y=0;y<height;y++){
		for(int x=0;x<width;x++){
	
			std::pair<double,double> coords=zoomList.doZoom(x,y);


			int iterations=Mandelbrot::getIterations(coords.first,coords.second);

			fractal[y*width+x]=iterations; 		//store the number of iterations for each pixel;

			if(iterations!=Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}
		}
	}

}

void FractalCreator::addZoom(const Zoom& zoom){
	zoomList.add(zoom);
}

void FractalCreator::getTotal(){

	for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++){ 		//count total number of pixels per iteration
		total+=histogram[i];
	}
}

void FractalCreator::drawFractal(){
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

						bitmap.setPixel(x,y,red,green,blue);
				}
			}
		}

}

void FractalCreator::writeBitmap(std::string fileName){
	bitmap.write(fileName);
}

