#include <emscripten/bind.h>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"
using namespace emscripten;


EMSCRIPTEN_BINDINGS(my_fractal) {

    //static const int height=600;
    //static const int width=600;

   class_<project::FractalCreator>("FractalCreator")
      .constructor<int,int>()
      .function("addRange", &project::FractalCreator::addRange)
      .function("addZoom",  &project::FractalCreator::addZoom)
      .function("run",&project::FractalCreator::run)
      ;

};


#include <emscripten/bind.h>
#include <string>
#include "RGB.h"

using namespace emscripten;


EMSCRIPTEN_BINDINGS(rgb) {
   class_<project::RGB>("RGB")
      .constructor<double,double,double>()
      .function("dumpVars", &project::RGB::dumpVars)
      ;
      emscripten::function("operator-",&project::operator-);

}