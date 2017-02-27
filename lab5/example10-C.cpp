//Example 10-C: Threshold
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("./images/birds.jpg",IMREAD_GRAYSCALE);
    int flags = WINDOW_GUI_NORMAL;
    Mat B;

    threshold(A,B,200,255,THRESH_BINARY);

    namedWindow("original",flags);
    imshow("original",A);

    namedWindow("THRESH_BINARY",flags);
    imshow("THRESH_BINARY",B);

    waitKey();
    return 0;
}