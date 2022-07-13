#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace project{


	Mandelbrot::Mandelbrot(){

	}
	Mandelbrot::~Mandelbrot(){

	}
	
	int Mandelbrot::getIterations(double x, double y){ 		//definition of the mandelbrot set


		//x and y must range from -1 to 1 since that is where our coordinate system is defined. 

		//the color of each pixel is determined by how quickly the coordinates become unstable accoridng to z*z+c;
		//for instance, 0,0 is obviously stable. the loop will keep running till it hits the MAX_ITERATIONS.
		//stable numbers will always be black. 
		//unstable numbers are colored based on how long it takes to reach |z|>2.
		//
		
		int iterations=0;

		complex<double> z=0;
		complex<double> c(x,y);


		while(iterations<MAX_ITERATIONS){
			z=z*z+c;
			if(abs(z)>2){
				break;
			}
			iterations++;
		}

		return iterations;

	}



}
