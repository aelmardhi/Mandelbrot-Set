#include "mandelbrot.h"
#include <chrono>
#include <iostream>

Complex Mandelbrot::scale(Complex c){
    Complex t (c.real() / (double)scr_.Width() * fract_.Width() + fract_.minX,
		c.imag() / (double)scr_.Height() * fract_.Height() + fract_.minY);
        return t;
}

int Mandelbrot::escape(Complex c){
    Complex z(0);
	int iter = 0;

	while (abs(z) < 2.0 && iter < iterMax_) {
		z = func_(z, c);
		iter++;
	}

	return iter;
}

void Mandelbrot::get_number_iterations(){
    int k = 0, progress = -1;
	for(int i = scr_.minY; i < scr_.maxY; ++i) {
		for(int j = scr_.minX; j < scr_.maxX; ++j) {
			Complex c((double)j, (double)i);
			c = scale(c);
			colors_[k] = escape(c);
			k++;
		}
		if(progress < (int)(i*100.0/scr_.maxY)){
			progress = (int)(i*100.0/scr_.maxY);
			// std::cout << progress << "%\n";
		}
	}
}

std::vector<int> Mandelbrot::fractal(){
    auto start = std::chrono::steady_clock::now();
	get_number_iterations();
	auto end = std::chrono::steady_clock::now();
	std::cout << "Time to generate " << " = " << std::chrono::duration <double, std::milli> (end - start).count() << " [ms]" << std::endl;

	// Save (show) the result as an image
	// plot(scr, colors, iter_max, fname, smooth_color);
    return colors_;
}
