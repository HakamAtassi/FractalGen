#include "ZoomList.h"


namespace project{

	ZoomList::ZoomList(int width, int height){

	}


	void ZoomList::add(const Zoom& zoom){


		zooms.push_back(zoom);
	}


	std::pair<double,double> doZoom(int x, int y){

		return std::pair<double,double>(0.0,0.0);


	}


}
