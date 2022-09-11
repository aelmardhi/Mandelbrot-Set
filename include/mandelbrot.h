#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>
#include <functional>
#include <vector>

#include "window.h"
using Complex = std::complex<double>;

class Mandelbrot {
public:
  Mandelbrot(Window<int> *scr, Window<double> *fract, int iterMax,
             const std::function<Complex(Complex, Complex)> &func)
      : scr_(*scr), fract_(*fract), iterMax_(iterMax), func_(func),
        colors_(std::vector<int>(scr_.Size())) {}
  std::vector<int> fractal();

private:
  Window<int> &scr_;
  Window<double> &fract_;
  std::vector<int> colors_;
  int iterMax_;
  const std::function<Complex(Complex, Complex)> &func_;
  Complex scale(Complex c);
  int escape(Complex c);
  void get_number_iterations();
};

#endif