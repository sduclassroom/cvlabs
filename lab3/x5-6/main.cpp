/*x5-6 Create a mask using cv::compare().

Load a real image. Use cv::split() to split the image into red, green, and blue images.
a. Find and display the green image.

b. Clone this green plane image twice (call these clone1 and clone2).

c. Find the green plane's minimum and maximum value.

d. Set clone1's values to thresh = (unsigned char)((maximum - minimum)/2.0).

e. Set clone2 to 0 and use cv::compare (green_image, clone1, clone2, cv::CMP_GE).
Now clone2 will have a mask of where the value exceeds thresh in the green image.

f. Finally, use cv::subtract (green_image,thresh/2,green_image,clone2) and display the results.

*/

#include <opencv2/opencv.hpp>
using namespace cv;


int main(int argc, char*argv[]) {
    // code here
    return 0;
}
