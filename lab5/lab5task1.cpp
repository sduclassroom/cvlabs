// Lab5 Task1: Binary Threshold Demo
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int t = 20;
int accept_color = 255;
Mat A,B;

void onThresholdChange(int pos, void*){
    t=pos;
    threshold(A,B,t,accept_color,THRESH_BINARY);
    imshow("THRESHOLD EXAMPLE",B);
}

void onColorChange(int pos, void*){
    accept_color=pos;
    threshold(A,B,t,accept_color,THRESH_BINARY);
    imshow("THRESHOLD EXAMPLE",B);
}

int main() {
    A = imread("images/page.jpg",IMREAD_GRAYSCALE);

    namedWindow("THRESHOLD EXAMPLE");
    namedWindow("ORIGINAL");
    imshow("ORIGINAL",A);

    createTrackbar("threshold","THRESHOLD EXAMPLE",&t,255,onThresholdChange);
    createTrackbar("color","THRESHOLD EXAMPLE",&accept_color,255,onColorChange);
    threshold(A,B,t,accept_color,THRESH_BINARY);
    imshow("THRESHOLD EXAMPLE",B);
    waitKey(0);
    return 0;
}