// Lab5 Task4: Morphological Operations
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat A,B;
int s = 3;


void onSizeChange(int pos, void*){
    s=pos;
    Mat S = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
    dilate(A,B,S);
    //erode(A,B,S);
    //morphologyEx(A,B,MORPH_BLACKHAT,S);
    imshow("DILATE",B);
}

int main() {
    A = imread("images/page.jpg",IMREAD_GRAYSCALE);
    bitwise_not(A,A);
    //threshold(A,A,150,255,THRESH_BINARY);

    namedWindow("ORIGINAL");
    imshow("ORIGINAL",A);
    createTrackbar("size","ORIGINAL",&s,25,onSizeChange);

    Mat S = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
    dilate(A,B,S);
    //erode(A,B,S);
    //morphologyEx(A,B,MORPH_BLACKHAT,S);

    namedWindow("DILATE");
    imshow("DILATE",B);
    waitKey(0);
    return 0;
}