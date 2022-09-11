#include "graphics.h"
#include <iostream>


int main() {
Graphics graphics;
std::cout << "This is a visualization of the Mandelbrot set. Click any Where to zoom" << "\n"
            << "[Left mouse button] to zoom in" << "\n";
graphics.join();
}