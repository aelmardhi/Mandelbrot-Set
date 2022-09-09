#include <string>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    std::string _windowName;
    int *value = new int;
    *value = 5;
    _windowName = "Concurrency Traffic Simulation";
    cv::namedWindow(_windowName, cv::WINDOW_NORMAL);
    cv::Mat mat (260, 301, CV_8UC3, cv::Scalar(0, 250, 0));
    for(int c=10;c<220;c++)
    for(int r=0; r<mat.rows;r++){
       cv::Vec3b color ;
       color.val[0] = c;
       color.val[1] = 120;
       color.val[2] = r;
       mat.at<cv::Vec3b>(cv::Point(c,r)) = color;
    }
    cv::Mat img;
    cv::resize(mat, img, cv::Size(1040,720),0,0,1);
    cv::imshow(_windowName, img);
    cv::waitKey(33);
    while(true);
}