#ifndef RGB_H_
#define RGB_H_


namespace project{

    struct RGB{

            double r;
            double g;
            double b;

            RGB();
            RGB(double r, double g,double b);  


            double dumpVars();

    };

    RGB operator- (const RGB& RGB1, const RGB& RGB2);
}





#endif
