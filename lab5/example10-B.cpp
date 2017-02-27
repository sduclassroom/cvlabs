//Example 10-B: Borders Extrapolation
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("./images/birds.jpg");
    Mat image2;
    int d = 50;
    int flags = WINDOW_GUI_NORMAL;
    namedWindow("NO BORDER",flags);
    imshow("NO BORDER",image);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REPLICATE);
    namedWindow("BORDER REPLICATE",flags);
    imshow("BORDER REPLICATE",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_WRAP);
    namedWindow("BORDER WRAP",flags);
    imshow("BORDER WRAP",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_CONSTANT,Scalar(0,0,123));
    namedWindow("BORDER CONSTANT",flags);
    imshow("BORDER CONSTANT",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REFLECT);
    namedWindow("BORDER REFLECT",flags);
    imshow("BORDER REFLECT",image2);

    cv::copyMakeBorder(image,image2,d,d,d,d,BORDER_REFLECT101);
    namedWindow("BORDER REFLECT101",flags);
    imshow("BORDER REFLECT101",image2);

    waitKey();
    return 0;
}