
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"


#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
namespace fs = std::filesystem;


using std::cout; using std::cin;
using std::endl; using std::ifstream;

int main(){

	project::BitmapFileHeader a;
	std::cout<<"header size:"<<sizeof(a)<<"\n";



	project::BitmapInfoHeader b;
	std::cout<<"info size:"<<sizeof(b)<<"\n";


	project::Bitmap c(800,600);
	c.write("packingtest.bmp");
	std::cout<<"Bitmap size:"<<sizeof(c)<<"\n";

	string path = "packingtest.bmp";

	std::cout<<"filesize: "<<fs::file_size(path)<<"\n";


}
