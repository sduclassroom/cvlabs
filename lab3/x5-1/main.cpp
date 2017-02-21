/* x5-1 (stub for the exercise)

This exercise will accustom you to the idea of many functions taking matrix
types. Create a two-dimensional matrix with three channels of type byte with
data size 100x100. Set all the values to 0.

a. Draw a circle in the matrix using
   void cv::circle(InputOutputArray img,cv::point center, intradius, cv::Scalar color, int thickness=1,int line_type=8, int shift=0) .

b. Display this image using methods described in Chapter 2.

*/

#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char*argv[]) {
    Mat M(100,100,CV_8UC3,Scalar(0,0,0));
    circle(M,Point(30,40),25,Scalar(0,0,255),2);
    imshow("M",M);
    waitKey(0);
    return 0;
}
