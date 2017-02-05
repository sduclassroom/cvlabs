//Example 2-1. A simple OpenCV program that loads an image from disk and displays it on the screen
#include <opencv2/opencv.hpp>
int main(int argc, char*argv[]) {
    cv::Mat img = cv::imread(argv[1],cv::IMREAD_COLOR); //lena.jpg
    //cv::Mat img = cv::imread(argv[1],cv::IMREAD_GRAYSCALE); //lena.jpg
    cv::namedWindow("Example1",cv::WINDOW_AUTOSIZE);
    //cv::namedWindow("Example1",cv::WINDOW_KEEPRATIO);
    cv::imshow("Example1",img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}
