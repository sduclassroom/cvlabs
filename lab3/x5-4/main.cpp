/* x5-4
Practice using region of interest (ROI).
Create a 210x210 single-channel byte image and zero it.
Within the image, build a pyramid of increasing values using
ROI and cv::Mat::setTo(). That is:
  the outer border should be 0, the next inner border should be 20,
  the next inner border should be 40, and so on until the final
  innermost square is set to value 200; all borders should be
  10 pixels wide.
Display the image.
*/
#include <opencv2/opencv.hpp>
using namespace cv;


int main(int argc, char*argv[]) {
    return 0;
}
