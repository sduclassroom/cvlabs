#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    Mat A = imread("../images/frame0.jpg");
    Mat B = imread("../images/frame50.jpg");
    Mat C,Cgray,D;
    absdiff(A,B,C);
    cvtColor(C,Cgray,COLOR_BGR2GRAY);

    threshold(Cgray,D,255*.2,255,THRESH_BINARY);


    vector<vector<Point> > contours;
    findContours(D,contours,RETR_LIST,CHAIN_APPROX_NONE);
    for(int i=0;i<contours.size();i++){
        rectangle(B,boundingRect(contours[i]),Scalar(0,255,0),1);
    }

    namedWindow("contours",WINDOW_KEEPRATIO);
    namedWindow("thresholded",WINDOW_KEEPRATIO);
    imshow("contours",B);
    imshow("thresholded",D);
    waitKey(0);
    return 0;
}