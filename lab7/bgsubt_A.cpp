#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    VideoCapture vcap("../images/bike.avi");
    double fps = vcap.get(CAP_PROP_FPS);

    if (!vcap.isOpened()) {
        cout << "Video could not be opened." << endl;
        return -1;
    }

    Mat bg;
    vcap >> bg;
    namedWindow("absdiff",WINDOW_KEEPRATIO);
    namedWindow("binary",WINDOW_KEEPRATIO);

    while(true){
        Mat frame, diff, bin, gray;
        vcap >> frame;

        if (frame.empty()) break;

        absdiff(frame,bg,diff); // diff = |frame - bg|
        cvtColor(diff,gray,COLOR_BGR2GRAY);
        threshold(gray,bin,30,255,THRESH_BINARY);

        erode(bin,bin,getStructuringElement(MORPH_RECT,Size(3,3)));
        dilate(bin,bin,getStructuringElement(MORPH_RECT,Size(15,15)));

        // your code here to find regions and draw rectangle around them


        imshow("absdiff",diff);
        imshow("binary",bin);
        //waitKey(1000/fps);
        char ch = waitKey(0);
        if (ch ==27) break;

    }
    vcap.release();
    return 0;
}