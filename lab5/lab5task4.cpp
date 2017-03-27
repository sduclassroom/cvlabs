// Lab5 Task4: Morphological Operations
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat A,B,C;
int s1 = 1;
int s2 = 1;


void onSize1Change(int pos, void *){
    if (pos==0) return;
    s1=pos;
    Mat S = getStructuringElement(MORPH_RECT,Size(s1,s2));
    dilate(A,B,S);
    erode(A,C,S);
    imshow("DILATE",B);
    imshow("ERODE",C);
}

void onSize2Change(int pos, void *){
    if (pos==0) return;
    s2=pos;
    Mat S = getStructuringElement(MORPH_RECT,Size(s1,s2));
    dilate(A,B,S);
    erode(A,C,S);
    imshow("DILATE",B);
    imshow("ERODE",C);
}

int main() {
    Mat Z = imread("images/page.jpg",IMREAD_GRAYSCALE);
    A = Z(Rect(0,0,200,200));
    namedWindow("ORIGINAL");
    imshow("ORIGINAL",A);
    createTrackbar("size1", "ORIGINAL", &s1, 25, onSize1Change);
    createTrackbar("size2", "ORIGINAL", &s2, 25, onSize2Change);
    Mat S = getStructuringElement(MORPH_RECT,Size(s1,s2),Point(-1,-1));
    dilate(A,B,S);
    erode(A,C,S);
    imshow("DILATE",B);
    imshow("ERODE",C);
    waitKey(0);
    return 0;
}
