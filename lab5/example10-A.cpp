//Example 10-A: Linear Filter = Convolution, in this case it is mean filter producing blurring effect
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A = imread("images/birds.jpg",IMREAD_GRAYSCALE);
    Mat B;
    Matx33f K = 1/9.0 * Matx33f::ones();
    filter2D(A, B, CV_8UC1, K);

    imshow("A",A);
    imshow("B",B);
    cout << K << endl;
    waitKey(0);

    return 0;
}
