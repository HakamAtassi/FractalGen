#include "FractalCreator.h"	
#include "Mandelbrot.h"
#include <math.h>
#include <iostream>
#include <cassert>
using namespace project;

int FractalCreator::run(string fileName){




	calculateIterations(); 
	getTotalIterations(); 
	getRangeTotals(); 
	drawFractal();
	writeBitmap(fileName);


	return 1;
}


void FractalCreator::addRange(double rangeEnd, const RGB& color){ 		//counts the number of pixeles in different ranges of iterations to deterime the colors
	//range end is a percentage of the maximum number of iterations. 
	ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
	colors.push_back(color);

	if(gotFirstRange){
		rangeTotals.push_back(0);
	}

	gotFirstRange=true;
}


void FractalCreator::getRangeTotals(){

	int rangeIndex=0;

	for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++){
		int pixels=histogram[i];

		if(i>=ranges[rangeIndex+1]){
			rangeIndex++;
		}
		rangeTotals[rangeIndex]+=pixels;
	}

	for(int value:rangeTotals){
		cout<<"Range totals: "<<value<<endl;
	}

}


int FractalCreator::getRange(int iterations) const{
	int bin=0; //bin is the number of the bin the number of iterations falls in
	//ie: 100 iterations falls within the 0th bin (0.0 to 0.3)


	for(int i=1;i<ranges.size();i++){ 		//ranges is the values of each bin
		//{0,300,500,700,1000} for instance
		bin=i;
		if(ranges[i]>iterations){
			break;
		}
	}


	bin--; 				//found the position where the next value is greater. subtract 1 for the bin value
	assert(bin>-1);
	assert(bin<ranges.size());



	return bin;
}



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

void FractalCreator::getTotalIterations(){

	for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++){ 		//count total number of pixels per iteration
		total+=histogram[i];
	}
}

void FractalCreator::drawFractal(){




	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){

			int iterations=fractal[y*width+x]; 		//store the number of iterations for each pixel;

			int range=getRange(iterations);
			int rangeTotal=rangeTotals[range];
			int rangeStart=ranges[range];

			RGB& startColor=colors[range];
			RGB& endColor=colors[range+1];
			RGB colorDiff=endColor-startColor;


			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			

			if(iterations!=Mandelbrot::MAX_ITERATIONS){

				double hue=0.0;
				int totalPixes=0;

				for(int i=rangeStart;i<=iterations;i++){ 		//hue is based on how common that pixel is
					totalPixes+=histogram[i];

				}


				red=startColor.r+colorDiff.r*(double)totalPixes/rangeTotal;
				green=startColor.g+colorDiff.g*(double)totalPixes/rangeTotal;
				blue=startColor.b+colorDiff.b*(double)totalPixes/rangeTotal;



				bitmap.setPixel(x,y,red,green,blue);
			}
		}
	}

}

void FractalCreator::writeBitmap(std::string fileName){
	bitmap.write(fileName);
}

