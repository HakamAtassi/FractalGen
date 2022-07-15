#ifndef BITMAP_H_
#define BITMAP_H_


#include <cstdint>
#include <string>
#include <memory>

using namespace std;


namespace project{

	class Bitmap{
	private:
		int width=0; //width and height start off as 0 (no image)
		int height=0;
		std::unique_ptr<uint8_t[]> pPixels{nullptr};
		

	public:
		Bitmap(int _width,int _height);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
		bool write(string filename); 	//write to file, return false if failed
		virtual ~Bitmap();


	};

} 		//namespace project


#endif
