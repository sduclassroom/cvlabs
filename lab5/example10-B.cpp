#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("./images/birds.jpg");
    Mat image2;
    int d = 50;
    imshow("NO BORDER",image);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REPLICATE);
    imshow("BORDER REPLICATE",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_WRAP);
    imshow("BORDER WRAP",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_CONSTANT,Scalar(0,0,123));
    imshow("BORDER CONSTANT",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REFLECT);
    imshow("BORDER REFLECT",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REFLECT101);
    imshow("BORDER REFLECT101",image2);

    waitKey();
    return 0;
}