//Example 4-0: Creating an array
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char*argv[]) {
    cv::Mat m; // no size, no data

    // Create data area for 100 rows and 200 columns of 3-channel 32-bit floats
    m.create(100,200,CV_32FC3 );

    // Set the values in the 1st channel to 1.0, the 2nd to 0.0, and the 3rd to 1.0
    m.setTo( cv::Scalar( 1.0f, 0.0f, 1.0f ) );

    // A short way of creating similar array as above
    cv::Mat mm(100,200, CV_32FC3, cv::Scalar( 0.0f, 1.0f, 0.0f ) );

    cv::imshow("m",m);
    cv::imshow("mm",mm);
    cv::waitKey(0);
    return 0;
}
