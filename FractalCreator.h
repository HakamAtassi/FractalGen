#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include <string>
#include <memory>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"

namespace project{

class FractalCreator{

private:
	int width{0};
	int height{0};
	int total{0};

	std::unique_ptr<int[]> histogram; //iterations:number of pixels
	std::unique_ptr<int[]> fractal; //pixel:iterations
	Bitmap bitmap;
	ZoomList zoomList;


public:

	FractalCreator(int width, int height); 		//size of image
	virtual ~FractalCreator();


	void calculateIterations(); //calculate the iterations of each pixel. Generate histograms
	void getTotal();
	void addZoom(const Zoom& zoom); 		//add zooms to zoom list and recenter
	void drawFractal(); 	//place bitmaps

	void writeBitmap(std::string); //generate .bmp file


};

}


#endif
