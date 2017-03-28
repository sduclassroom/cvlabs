// Lab6 - Deskewing Number Plate
// This stub is almost complete ( we did it with groups 3EN[ABCD]03 )
// It finds all line segment using HoughLinesP, draws them in red color,
// finds the longest line segment and draws it in green color
// It is up to you find the angle and rotate it using warpAffine()

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    // step 0: read an image
//    Mat A = imread("../plates/plate01.png");
    Mat A = imread("../plates/plate02.png");
//    Mat A = imread("../plates/plate03.png");
//    Mat A = imread("../plates/plate04.png");
//    Mat A = imread("../plates/plate05.png");
//    Mat A = imread("../plates/plate06.png");
//    Mat A = imread("../plates/plate07.png");

    namedWindow("window",WINDOW_KEEPRATIO);
    imshow("window",A);
    waitKey(0);

    // step 1: find the edges
    Mat B;
    Canny(A,B,150,450); // 200 and 400 are threshold1 and threshold2 of Canny's hysteresis algorithm
    imshow("window",B);
    waitKey(0);

    // step 2: find line segments using HoughLinesP
    Mat C;
    cvtColor(B,C,COLOR_GRAY2BGR); // C is just 3 channel version of B (i.e. colorful) because we want to draw colorful lines on it
    vector<Vec4f> lines; // each element contains 4 numbers: x1 y1 x2 y2, the coordinate of the extreme 2 points of the line segments

    HoughLinesP(B, // edge matrix
                lines, // array of line segments
                1, // drho
                CV_PI/180, // dtheta
                B.cols/2, // minimum number of pixels on a line segment
                B.cols/2, // minimum length of a line segment
                10); // maximum allowed gap between 2 line segment to be merged into one single line segment

    // step 3: draw all line segments
    for( int i = 0; i < lines.size(); i++ )
    {
        line( C, Point(lines[i][0],lines[i][1]),
              Point(lines[i][2],lines[i][3]),
              Scalar(0,0,255),
              1);
    }

    // step 4: find and draw the longest line segment
    int k = 0; // lines[k] is the current longest line segment
    Point pk1(lines[k][0],lines[k][1]); // (x1,y1)
    Point pk2(lines[k][2],lines[k][3]); // (x2,y2)
    double knorm = norm(pk1-pk2); // Pythagorean Theorem

    for( int i = 1; i < lines.size(); i++ )
    {
        Point p1(lines[i][0],lines[i][1]);
        Point p2(lines[i][2],lines[i][3]);
        double inorm = norm(p1-p2);

        if (inorm>knorm) { // update k, knorm and points
            knorm = inorm;
            pk1 = p1;
            pk2 = p2;
            k=i;
        }
    }

    line(C, pk1, pk2, Scalar(0,255,0), 1); // green line segment
    imshow("window",C);
    waitKey(0);


    // step 5: find the angle and rotate the initial image to deskew it

    // your code to rotate using warpAffine ?
}
