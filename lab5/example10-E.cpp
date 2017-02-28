//Example 10-E: Adaptive threshold
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("./images/page.jpg",IMREAD_GRAYSCALE);
    Mat B,C,D;

    adaptiveThreshold(A,B,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY, 7, 10);
    adaptiveThreshold(A,C,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY, 7, 10);
    threshold(A,D,0,255,THRESH_OTSU);

    imshow("ADAPTIVE_THRESH_MEAN_C",B);
    imshow("ADAPTIVE_THRESH_GAUSSIAN_C",C);
    imshow("THRESH_OTSU",D);
    waitKey();
    return 0;
}