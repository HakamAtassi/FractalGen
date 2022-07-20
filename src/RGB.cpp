#include "RGB.h"
#include "iostream"

using namespace project;

RGB::RGB(){
}


RGB::RGB(double _r, double _g, double _b):r(_r),g(_g),b(_b){
    
}


double RGB::dumpVars(){
 
    return r;
}

RGB project::operator- (const RGB& RGB1, const RGB& RGB2){
	return RGB(RGB1.r-RGB2.r,RGB1.g-RGB2.g,RGB1.b-RGB2.b);
}
