#ifndef RGB_H_
#define RGB_H_


namespace project{

	struct RGB{

		double r{0};
		double g{0};
		double b{0};



		RGB(double r, double g, double b);


	};

		RGB operator- (const RGB& RGB1, const RGB& RGB2);


}





#endif
