#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace project{


	Mandelbrot::Mandelbrot(){

	}
	Mandelbrot::~Mandelbrot(){

	}
	
	int Mandelbrot::getIterations(double x, double y){ 		//definition of the mandelbrot set
		
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
