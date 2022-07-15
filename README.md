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
The mapping process determines wether the pixel at some specified x,y coordinate falls within the Mandelbrot set. This task is quite simple and is demonstrated in the following pseudo-code:


```
for x in width of image  
  for y in height of image  
    count=0
    z=imaginary(x,y)  
    c=z
    while count<1000 and |z|<2  
      z=z*z+c
      count++
```
&nbsp;&nbsp;&nbsp;&nbsp;If count, the number of times the formula $z$=$z^2$+$c$ is applied, is 1000, the number is considered stable and within the Mandelbrot set. If count is under 1000, then the number exceeded the abitrary bound of 2 and is not considered to be part of the Mandelbrot set.  
&nbsp;&nbsp;&nbsp;&nbsp;The result of count for each pixel is stored in an array named fractal. The number of pixels for each possible count is stored in an array named histogram. This data is crutial to the coloring of the fractal.

### Coloring
blah blah blah

