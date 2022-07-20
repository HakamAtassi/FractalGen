#include <emscripten/bind.h>
#include <string>
#include "RGB.h"

using namespace emscripten;


EMSCRIPTEN_BINDINGS(rgb) {
   class_<project::RGB>("RGB")
      .constructor<double,double,double>()
      .function("dumpVars", &project::RGB::dumpVars)
      ;
      function("operator-",&project::operator-);

}

