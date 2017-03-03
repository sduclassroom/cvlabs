//Example 10-F: Edge Detection with Sobel Derivative
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("images/akorda.jpg",IMREAD_GRAYSCALE);
    Mat dAdx,dAdy;

    Sobel(A,dAdx,CV_16SC1,1,0,3);
    Sobel(A,dAdy,CV_16SC1,0,1,3);

    imshow("A",A);

    convertScaleAbs(dAdx,dAdx); // normalizing
    convertScaleAbs(dAdy,dAdy); //

    threshold(dAdx,dAdx,200,255,THRESH_BINARY); // leave only values higher than 200
    threshold(dAdy,dAdy,200,255,THRESH_BINARY);

    imshow("dA/dx",dAdx); // vertical edges
    imshow("dA/dy",dAdy); // horizontal edges
    imshow("dA/dx + dA/dy", dAdx + dAdy); // both vertical and horizontal edges

    waitKey(0);
    return 0;
}