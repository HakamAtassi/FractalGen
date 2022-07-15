<h1 align="center"> FractalGen
<h4 align="center">Generate colorful Mandelbrot fractals using modern C++ and advanced programming principles.
<br></br>
<br></br>

Original             |  Zoomed
:-------------------------:|:-------------------------:
![](img/bitmap.bmp)  |  ![](img/bitmap_zoomed.bmp)

### Build and Run 

To build and run:
```
cd 
git clone https://github.com/HakamAtassi/fractalGen
cd fractalGen/src
make run
```
and open Fractal.bmp in /src to view the generated fractal.

<br></br>

## The Mandelbrot Set
The Mandelbrot set is the set of (imaginary) numbers whose magnitudes do not exceed some arbitrary bound when recursively squared and added to themselves. 
This relationship can be represented as $z$=$z^2$+$c$, where $c$ is the inital coordinate. In this case, the maximum bound of |$z$| is 2, and the number of iterations per number is 1000. 


## Algorithms
The construction of the Mandelbrot fractal involves 2 main algorithms: the first to determine the pixels that fall within the Mandelbrot set, and the second to apply coloring to the pixels that do not fall within the set. 

  
  
### Mapping
blah blah blah

  
### Coloring
blah blah blah
