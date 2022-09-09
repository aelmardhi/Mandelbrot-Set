#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <functional>
#include <complex>

#include "window.h"
using Complex = std::complex<double>;

class Mandelbrot{
    public:
    Mandelbrot( Window<int> &src, Window<double> &fract, int iterMax, const std::function<Complex( Complex, Complex)> &func):src_(src), fract_(fract), iterMax_(iterMax), func_(func){}

    private:
    Window<int> &src_;
    Window<double> &fract_;
    int iterMax_;
    const std::function<Complex( Complex, Complex)> &func_;
    Complex scale(Complex c);
    int escape(Complex c);
    void get_number_iterations();
    void fractal();
};

#endif