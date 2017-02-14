//X2-6. Use of trackbar to change the size of an image.
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main(int argc, char*argv[]) {
    Mat img = imread(argv[1],IMREAD_COLOR);
    Mat img2;
    int w=100,h=100;
    namedWindow("1",WINDOW_AUTOSIZE);
    createTrackbar("w","1",&w,img.cols*2);
    createTrackbar("h","1",&h,img.rows*2);
    imshow("1",img);
    std::cout << "Set the two trackbars to desired positions and press any key\n";
    waitKey(0);

    resize(img,img2,Size(w,h));
    namedWindow("2",WINDOW_AUTOSIZE);
    imshow("2",img2);
    waitKey(0);
    return 0;
}
