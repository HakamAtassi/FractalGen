#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;




//bitmap file header goes at the top of the bitmap file.
//tells user what the file contains. 
//see http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm


#pragma pack(2) 		//remove padding from struct

namespace project {

struct BitmapFileHeader{ 		//data that will be written to file

	char header[2]{'B','M'};
	int32_t fileSize;
	int32_t reserved=0;
	int32_t dataOffset;

};

}




#endif

