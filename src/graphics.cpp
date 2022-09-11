#include "graphics.h"

#include <chrono>
#include <iostream>


cv::Vec3b Graphics::get_rgb_piecewise_linear(int n, int iter_max) {
  cv::Vec3b color;
  int N = 256; // colors per element
  int N3 = N * N * N;
  // map n on the 0..1 interval (real numbers)
  double t = (double)n / (double)iter_max;
  // expand n on the 0 .. 256^3 interval (integers)
  n = (int)(t * (double)N3);

  color.val[2] = n / (N * N);
  int nn = n - color.val[2] * N * N;
  color.val[0] = nn / N;
  color.val[1] = nn - color.val[0] * N;
  return color;
}

cv::Vec3b Graphics::get_rgb_smooth(int n, int iter_max) {
  // map n on the 0..1 interval
  double t = (double)n / (double)iter_max;
  cv::Vec3b color;
  // Use smooth polynomials for r, g, b
  color.val[0] = (int)(9 * (1 - t) * t * t * t * 255);
  color.val[1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
  color.val[2] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
  return color;
}

cv::Mat Graphics::get_image(){
  Mandelbrot set(scr_, fract_, iterMax_, func_);
  auto colors = set.fractal();
  cv::Mat mat(scr_.Height(), scr_.Width(), CV_8UC3, cv::Scalar(0, 250, 0));
  int n = 0;
  for (int i = scr_.minY; i < scr_.maxY; ++i) {
    for (int j = scr_.minX; j < scr_.maxX; ++j) {

      mat.at<cv::Vec3b>(cv::Point(j, i)) =
          get_rgb_smooth(colors[n++], iterMax_);
    }
  }
  return mat;
}

Graphics::Graphics() :
scr_(0, 1200, 0, 1200),
fract_(-1.5, 1.5, -1.5, 1.5),
func_ ( [](Complex z, Complex c) -> Complex { return z * z + c; }),
iterMax_ (500),
_windowName ("Concurrency Traffic Simulation")
 {
  cv::namedWindow(_windowName, cv::WINDOW_NORMAL);
  cv::Mat mat = get_image();
  cv::Mat img;
  cv::resize(mat, img, cv::Size(1040, 720), 0, 0, 1);
  cv::imshow(_windowName, img);
  cv::waitKey(33);
  thread_ = std::thread([this,img]{
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cv::imshow(_windowName, img);
		cv::waitKey(33);
	}
  });
  
}

void Graphics::join(){
	thread_.join();
}

// static void Graphics::onMouse( int event, int x, int y, int flags, void* param )
// {
// 	mousex = x;
// 	mousey = y;
	

//     if(event == CV_EVENT_LBUTTONDOWN)
// 		imagen = zoomIn(x, y);
// 	else if(event == CV_EVENT_RBUTTONDOWN)
// 		imagen = zoomOut(x, y);
// }