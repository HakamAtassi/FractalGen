#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include <string>
#include <memory>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"


#include <vector>

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

			vector<int> ranges; //the actual ranges or "bins" (percentages of max it)
			vector<RGB> colors;
			vector<int> rangeTotals; 		//stores the number of pixes per range

			bool gotFirstRange=false;

		public:
			FractalCreator(int width, int height); 		//size of image
			virtual ~FractalCreator();
			void addZoom(const Zoom& zoom); 		//add zooms to zoom list and recenter
			void addRange(double rangeEnd, const RGB& rgb);

		private:

			void calculateIterations(); //calculate the iterations of each pixel. Generate histograms
			void getTotalIterations();
			void drawFractal(); 	//place bitmaps
			void getRangeTotals();

			void writeBitmap(std::string); //generate .bmp file
			int getRange(int iterations) const; 		//not allowed to modify member vars

		public:
			int run(string name);

	};

}


#endif
