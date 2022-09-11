#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <functional>
#include <thread>

#include "mandelbrot.h"
#include "window.h"

#include <string>
#include <memory>

class Graphics {
public:
  Graphics();
  void join();

private:
  cv::Vec3b get_rgb_piecewise_linear(int n, int iter_max);
  cv::Vec3b get_rgb_smooth(int n, int iter_max);
  cv::Mat get_image();
  std::unique_ptr<cv::Mat> img_;
  std::unique_ptr<Mandelbrot> set_;
  std::thread thread_;
  std::unique_ptr<Window<int>> scr_;
  // The domain in which we test for points
  std::unique_ptr<Window<double>> fract_;
  // The function used to calculate the fractal
  std::function<Complex(Complex,Complex)> func_ ;
  int iterMax_ ;
  std::string _windowName ;
  static void onMouse( int event, int x, int y, int flags, void* param );
  void zoomIn(double x, double y);
  void zoomOut(double x, double y);
  static constexpr int WIDTH {1920};
  static constexpr int HEIGHT {1080};
};

#endif