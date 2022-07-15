#include <fstream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"


using namespace project;

namespace project {

	Bitmap::Bitmap(int _width, int _height):width(_width), height(_height),pPixels(new uint8_t[_width*_height*3]{}) { 	//pPixels is a pointer to an array of the color range for every pixel (rgb for each pixel)
		
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

		uint8_t* pixel=pPixels.get();
		pixel+=(y*3)*width+(x*3); //to move downwards add the entire width. to move right just add x
		//multiply by 3 because each pixel has 3 entries

		pixel[0]=blue;
		pixel[1]=green;
		pixel[2]=red;

	}

	bool Bitmap::write(string filename){
		project::BitmapFileHeader fileHeader;
		project::BitmapInfoHeader infoHeader;


		fileHeader.fileSize=sizeof(BitmapFileHeader)+sizeof(BitmapInfoHeader)+width*height*3; //size of the entire file is the size of file info and the content
		//which is the number of pixels times the about of data per pixel
		fileHeader.dataOffset=sizeof(BitmapInfoHeader)+sizeof(BitmapFileHeader); 		//offset is where the data starts

		infoHeader.width=width;
		infoHeader.height=height;

	

		/**writing to file**/

		ofstream file;
		file.open(filename, ios::out | ios::binary); 		//ofstrea.open flags can be combined using | operator

		if(!file){
			return false;
		}

		file.write((char*) &fileHeader,sizeof(fileHeader));
		file.write((char*) &infoHeader,sizeof(infoHeader));

		file.write((char *) pPixels.get(),width*height*3); 		

		file.close();
		
		if(!file){
			return false;
		}

		return true;
	}



	Bitmap::~Bitmap(){

	}

}
