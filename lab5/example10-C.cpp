//Example 10-C: Threshold
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("./images/test.jpg",IMREAD_GRAYSCALE);
    int flags = WINDOW_GUI_EXPANDED;
    Mat B;

    threshold(A,B,150,255,THRESH_BINARY);

    namedWindow("original",flags);
    imshow("original",A);

    namedWindow("THRESH_BINARY",flags);
    imshow("THRESH_BINARY",B);

    namedWindow("THRESH_BINARY zoomed",flags);
    imshow("THRESH_BINARY zoomed",B);

    waitKey();
    return 0;
}