#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // step 0
    Mat A = imread("../plates/plate01.png");
    namedWindow("window",WINDOW_KEEPRATIO);
    imshow("window",A);
    waitKey(0);

    // step1
    Mat B;
    Canny(A,B,200,400);
    imshow("window",B);
    waitKey(0);

    // step 2:
    Mat C;
    cvtColor(B,C,COLOR_GRAY2BGR);

    vector<Vec4f> lines;
    HoughLinesP(B,lines,1,CV_PI/180,B.rows/2,50,5);

    //
    for( int i = 0; i < lines.size(); i++ )
    {
        line( C, Point(lines[i][0],lines[i][1]),
              Point(lines[i][2],lines[i][3]),
              Scalar(0,0,255),
              1);
    }

    int k = 0;
    Point pk1(lines[k][0],lines[k][1]);
    Point pk2(lines[k][2],lines[k][3]);
    int knorm = norm(pk1-pk2); // Pythagorean Theorem

    for( int i = 1; i < lines.size(); i++ )
    {
        Point p1(lines[i][0],lines[i][1]);
        Point p2(lines[i][2],lines[i][3]);
        int inorm = norm(p1-p2);

        if (inorm>knorm) {
            knorm = inorm;
            pk1 = p1;
            pk2 = p2;
            k=i;
        }
    }

    line( C, Point(lines[k][0],lines[k][1]),
          Point(lines[k][2],lines[k][3]),
          Scalar(0,255,0),
          1);

    // your code to rotate using warpAffine ?

    imshow("window",C);
    waitKey(0);
}
