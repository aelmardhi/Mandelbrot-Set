#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "mandelbrot.h"
#include "window.h"

#include <string>

class Graphics {
public:
  Graphics();

private:
  cv::Vec3b get_rgb_piecewise_linear(int n, int iter_max);
  cv::Vec3b get_rgb_smooth(int n, int iter_max);
//   Window<int> scr_;
//   // The domain in which we test for points
//   Window<double> fract_;
//   // The function used to calculate the fractal
// //   auto func_ = [](Complex z, Complex c) -> Complex { return z * z + c; };
//   int iterMax_ ;
//   std::string _windowName ;
};

#endif