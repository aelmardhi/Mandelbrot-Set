#include "graphics.h"
#include <iostream>


int main() {
Graphics graphics;
std::cout << "This is a visualization of the Mandelbrot set. Click any Where to zoom" << "\n"
            << "[Left Mouse Button] to zoom in   |  [Right Mouse Button] to zoom out" << "\n";
graphics.join();
}