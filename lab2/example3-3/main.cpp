//Example 3-3. Size and Rect
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    Mat A = imread("croc.jpg");
    Mat B;

    Size sz(200,300);
    cout <<"New size = " << sz << endl;
    cout <<"width = " << sz.width << endl;
    cout <<"height = " << sz.height << endl;
    cout <<"area = " << sz.area() << endl;
    resize(A,B,sz);
    imshow("A",A);
    imshow("B",B);
    waitKey(0);

    Rect r(50,20,200,100);
    cout << r << endl;
    Mat C = A(r);

    circle(C,Point(20,20),5,Scalar(0,255,0),2);
    imshow("C",C);
    imshow("A",A);
    waitKey(0);

    return 0;
}
