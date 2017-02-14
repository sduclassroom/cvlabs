/*x3-1.
Find and open .../opencv/cxcore/include/cxtypes.h.
Read through and find the many conversion helper functions.

a. Choose a negative floating-point number.
b. Take its absolute value, round it, and then take its ceiling and floor.
c. Generate some random numbers.
d. Create a floating-point cv::Point2f and convert it to an integer cv::Point.
Convert a cv::Point to a cv::Point2f .
*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char*argv[]) {
    //a
    float f=-3.3F;
    cout << "f = " << f << endl;
    cout << "abs(f) = " << abs(f) << endl;
    cout << "cvRound(f) = " << cvRound(f) << endl;
    cout << "cvCeil(f) = " << cvCeil(f) << endl;
    cout << "cvFloor(f) = " << cvFloor(f) << endl;

    //b
    RNG R(3);
    for(int i=0;i<10;i++) cout << R.next()%600 << endl;

    //c
    Point2f a(1.5,2.1);
    Point b = (Point)a;
    cout << a << endl;
    cout << fixed << b << endl;
    cout << fixed << (Point2f)b << endl;

    return 0;
}
