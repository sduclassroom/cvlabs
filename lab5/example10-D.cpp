//Example 10-D: Otsu threshold & Triangle threshold
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("./images/test_small.jpg",IMREAD_GRAYSCALE);
    int flags = WINDOW_GUI_NORMAL | WINDOW_AUTOSIZE;
    Mat B,C,D;

    double otsu_t = threshold(A,B,0,255,THRESH_OTSU);
    double triangle_t = threshold(A,C,0,255,THRESH_TRIANGLE);
    double t = threshold(A,D,150,255,THRESH_BINARY);

    namedWindow("original",flags);
    imshow("original",A);

    namedWindow("THRESH_OTSU",flags);
    imshow("THRESH_OTSU",B);

    namedWindow("THRESH_TRIANGLE",flags);
    imshow("THRESH_TRIANGLE",C);

    namedWindow("THRESH_BINARY",flags);
    imshow("THRESH_BINARY",D);


    cout << "Threshold value computed by Otsu algorithm = " << otsu_t << endl;
    cout << "Threshold value computed by Triangle algorithm = " << triangle_t << endl;
    cout << "Threshold value for Bi-level simple threshold = " << t << endl;


    waitKey();
    return 0;
}