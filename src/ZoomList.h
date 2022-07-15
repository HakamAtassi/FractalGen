#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_


#include "Zoom.h"
#include <vector>
#include <utility>

namespace project{

	class ZoomList{
		private:

			double xCenter{0};
			double yCenter{0};
			double scale{1};

			int width=0;
			int height=0;
			std::vector<Zoom> zooms;


		public:
			ZoomList(int width, int height);
			void add(const Zoom& zoom);
			std::pair <double,double> doZoom(int x, int y);
	};

}





#endif
