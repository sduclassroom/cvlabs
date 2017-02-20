//Example 4-00: Accessing Elements
#include <opencv2/opencv.hpp>
#include <cstdio>

using namespace cv;

int main(int argc, char*argv[])
{
    cv::Mat m = cv::Mat::eye(10,10,CV_32FC1);
    printf("Element m(3,3) is %f\n",m.at<float>(3,3));

    cv::Mat n = cv::Mat::eye(10,10,CV_32FC2);
    printf("Element n(3,3) is (%f,%f)\n",
           n.at<cv::Vec2f>(3,3)[0],
           n.at<cv::Vec2f>(3,3)[1]
          );
    return 0;
}
