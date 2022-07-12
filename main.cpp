#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"


#include <iostream>

using namespace project;

int main(){

	

	Bitmap b(600,800);
	b.setPixel(300, 400, 255, 255, 255);

	b.write("bitmap.bmp");


	std::cout<<"Bitmap generated.\n";
	

}
