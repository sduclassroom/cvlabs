/*x5-3
Create a three-channel RGB image of size 100x100. Clear it.
Use pointer arithmetic to draw a green square between (20, 5) and (40, 20).
*/
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    Mat M(300,300,CV_8UC3,Scalar(0,0,0));

    long t0 = getTickCount();

    for(int i=5;i<=200;i++){
        Vec3b* p = M.ptr<Vec3b>(i);
        for(int j=20;j<=40;j++)
            p[j][1] = 255;
    }

    long t1 = getTickCount();

    cout << t1 - t0 << endl;

    imshow("M",M);
    waitKey(0);
    return 0;
}

