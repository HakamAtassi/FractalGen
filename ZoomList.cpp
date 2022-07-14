#include "ZoomList.h"
#include <iostream>
using namespace std;

namespace project{

	ZoomList::ZoomList(int width, int height):width(width),height(height){

	}


	void ZoomList::add(const Zoom& zoom){
		zooms.push_back(zoom);



		xCenter+=(zoom.x-width/2)*scale;
		yCenter+=(zoom.y-height/2)*scale;

		
		scale*=zoom.scale;

		cout<<"xCenter:"<< xCenter<<"\n";
		cout<<"yCenter:"<<yCenter<<"\n";
		cout<<"scale:"<<scale<<"\n";


	}


	std::pair<double,double> ZoomList::doZoom(int x, int y){

		double xFractal = (x-width/2)*scale+xCenter;
		double yFractal = -(y-height/2)*scale+yCenter;

		//std::cout<<scale<<", ";


		return std::pair<double,double>(xFractal,yFractal);


	}


}
