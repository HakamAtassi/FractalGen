#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include <memory>
#include <math.h>
#include "FractalCreator.h"

#include "RGB.h"
#include <cstdint>
#include <iostream>

using namespace project;

int main(){
	static const int height=600;
	static const int width=800;

	FractalCreator fractalCreator(width,height);
	fractalCreator.addRange(0.0,RGB(0,0,0)); //based on how many iterations the pixel takes
	//color it accoridngly. 
	//could progrably be improved. this is very clunky at the moment

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(255, 99, 71));
	fractalCreator.addRange(0.08, RGB(255, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));


	fractalCreator.addZoom(Zoom(295,202,0.1));
	//fractalCreator.addZoom(Zoom(width/2.5,height/2,0.6));
	//fractalCreator.addZoom(Zoom(312,304,0.1));
	
	fractalCreator.run("bitmap.bmp");

	//fractalCreator.addZoom(Zoom(width/2,height/2,4.0/width));
	std::cout<<"Bitmap generated.\n";
	

}
