#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include <string>
#include "Zoom.h"

namespace project{

class FractalCreator{

private:
	int width{0};
	int height{0};

public:

	FractalCreator(int width, int height); 		//size of image
	virtual ~FractalCreator();


	void calculateIterations(); //calculate the iterations of each pixel. Generate histograms
	void addZoom(const Zoom& zoom); 		//add zooms to zoom list and recenter
	void drawFractal(); 	//place bitmaps

	void WriteBitmap(std::string); //generate .bmp file


};

}


#endif
