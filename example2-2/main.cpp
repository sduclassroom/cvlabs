//Example 2-2. A simple OpenCV program that loads an image from disk and displays it on the screen
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char*argv[]) {
    Mat img = imread(argv[1],IMREAD_COLOR); //lena.jpg
    namedWindow("Example2",WINDOW_AUTOSIZE);
    imshow("Example2",img);
    waitKey(0);
    destroyWindow("Example2");
    return 0;
}
