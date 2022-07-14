#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include <memory>
#include <math.h>
#include "FractalCreator.h"

#include <cstdint>
#include <iostream>

using namespace project;

int main(){



	FractalCreator fractalCreator(800,600);


	double min=999999;
	double max=-999999;

	static const int height=600;
	static const int width=800;


	
	//fractalCreator.addZoom(Zoom(width/2,height/2,4.0/width));
	fractalCreator.addZoom(Zoom(295,height-202,0.1));
	fractalCreator.addZoom(Zoom(312,height-304,0.1));



	fractalCreator.calculateIterations();
	fractalCreator.getTotal();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("bitmap.bmp");
	std::cout<<"Bitmap generated.\n";
	

}
