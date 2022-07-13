#ifndef ZOOM_H_
#define ZOOM_H_


namespace project{
	
	struct Zoom{
		int x{0};
		int y{0};
		double scale{0};
		Zoom(int x, int y, int scale):x(x),y(y),scale(scale){};
	};



}


#endif
