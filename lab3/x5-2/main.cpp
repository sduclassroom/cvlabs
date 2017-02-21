/* x5-2
Create a two-dimensional matrix with three channels of type byte
with data size 100x100, and set all the values to 0.

Use the cv::Mat element access functions to modify the pixels.
Draw a green rectangle between
(20,5) and (40,20) without using drawing functions.
*/
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    Mat M(300,300,CV_8UC3,Scalar(0,0,0));

    long t0 = getTickCount();
    for(int i=5;i<=200;i++)
    for(int j=20;j<=40;j++)
        M.at<Vec3b>(i,j)[1] = 255;

    long t1 = getTickCount();

    cout << t1 - t0 << endl;

    imshow("M",M);
    waitKey(0);
    return 0;
}
