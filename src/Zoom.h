#ifndef ZOOM_H_
#define ZOOM_H_


namespace project{
	
	struct Zoom{
		int x{0};
		int y{0};
		double scale{1};
		Zoom(){};
		Zoom(int x, int y, double scale):x(x),y(y),scale(scale){};
	};



}


#endif
