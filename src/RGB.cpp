#include "RGB.h"
#include <iostream>
using namespace project;


RGB::RGB(double r, double g, double b):r(r),g(g),b(b){

}


RGB project::operator- (const RGB& RGB1, const RGB& RGB2){
	
	
	return RGB(RGB1.r-RGB2.r,RGB1.g-RGB2.g,RGB1.b-RGB2.b);
}
