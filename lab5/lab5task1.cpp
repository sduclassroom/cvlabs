// Lab5 Task1: Binary Threshold Demo
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int s=7;
int c=100;

Mat A,Bmean,Bgaus;

void onCChange(int newc, void*){
    c = newc;
    adaptiveThreshold(A,Bmean,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,s/2*2+1,c-100);
    adaptiveThreshold(A,Bgaus,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,s/2*2+1,c-100);
    imshow("MEAN",Bmean);
    imshow("GAUSSIAN",Bgaus);
}

void onSize1Change(int news, void *){
    s = news;
    adaptiveThreshold(A,Bmean,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,s/2*2+1,c-100);
    adaptiveThreshold(A,Bgaus,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,s/2*2+1,c-100);
    imshow("MEAN",Bmean);
    imshow("GAUSSIAN",Bgaus);

}

int main() {
    A = imread("images/page.jpg",IMREAD_GRAYSCALE);

    namedWindow("ORIGINAL");
    imshow("ORIGINAL",A);

    createTrackbar("c","ORIGINAL",&c,200,onCChange);
    createTrackbar("size", "ORIGINAL", &s, 100, onSize1Change);
    adaptiveThreshold(A,Bmean,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,s/2*2+1,c-100);
    adaptiveThreshold(A,Bgaus,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,s/2*2+1,c-100);
    imshow("MEAN",Bmean);
    imshow("GAUSSIAN",Bgaus);
    waitKey(0);
    
    return 0;
}