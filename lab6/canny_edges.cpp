#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int t1=100;
int t2=200;
Mat A,B;

void onThreshold1Change(int t, void *){
    t1=t;
    Canny(A,B,t1,t2);
    imshow("Canny Edges",B);
}

void onThreshold2Change(int t, void *){
    t2=t;
    Canny(A,B,t1,t2);
    imshow("Canny Edges",B);
}

int main() {
    A = imread("../images/akorda.jpg");
    namedWindow("original",WINDOW_AUTOSIZE);
    imshow("original",A);
    createTrackbar("t1","original",&t1,1000,onThreshold1Change);
    createTrackbar("t2","original",&t2,1000,onThreshold2Change);
    Canny(A,B,t1,t2);
    imshow("Canny Edges",B);
    waitKey(0);
    return 0;
}