#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "mandelbrot.h"
#include "window.h"

cv::Vec3b get_rgb_piecewise_linear(int n, int iter_max) {
    cv::Vec3b color;
	int N = 256; // colors per element
	int N3 = N * N * N;
	// map n on the 0..1 interval (real numbers)
	double t = (double)n/(double)iter_max;
	// expand n on the 0 .. 256^3 interval (integers)
	n = (int)(t * (double) N3);

	color.val[2] = n/(N * N);
	int nn = n - color.val[2] * N * N;
	color.val[0] = nn/N;
	color.val[1] = nn - color.val[0] * N;
	return color;
}

cv::Vec3b get_rgb_smooth(int n, int iter_max) {
	// map n on the 0..1 interval
	double t = (double)n/(double)iter_max;
    cv::Vec3b color;
	// Use smooth polynomials for r, g, b
	color.val[0] = (int)(9*(1-t)*t*t*t*255);
	color.val[1] = (int)(15*(1-t)*(1-t)*t*t*255);
	color.val[2] =  (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);	
	return color;
}

int main(){

    Window<int> scr(0, 1200, 0, 1200);
	// The domain in which we test for points
	Window<double> fract(-1.5, 1.5, -1.5, 1.5);

	// The function used to calculate the fractal
	auto func = [] (Complex z, Complex c) -> Complex {return z * z + c; };

	int iter_max = 500;
    Mandelbrot set(scr, fract, iter_max, func);
    auto colors = set.fractal();
    std::string _windowName;
    _windowName = "Concurrency Traffic Simulation";
    cv::namedWindow(_windowName, cv::WINDOW_NORMAL);
    cv::Mat mat (scr.Height(), scr.Width(), CV_8UC3, cv::Scalar(0, 250, 0));
    int n=0;
    for(int i = scr.minY; i < scr.maxY; ++i) {
		for(int j = scr.minX; j < scr.maxX; ++j) {
      
            mat.at<cv::Vec3b>(cv::Point(j,i)) = get_rgb_smooth(colors[n++],iter_max);
        }
    }
    cv::Mat img;
    cv::resize(mat, img, cv::Size(1040,720),0,0,1);
    cv::imshow(_windowName, img);
    cv::waitKey(33);
    while(true)
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}