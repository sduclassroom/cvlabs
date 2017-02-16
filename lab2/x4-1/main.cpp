/*x4-1
Create a 500x500 single channel uchar image with every pixel equal to zero.

a. Create an ASCII numeric typewriter where you can type numbers into your computer
   and have the number show up in a 20-pixel-high by 10-pixel-wide block. As you type,
   the numbers will display from left to right until you hit the end of the image.
   Then just stop.
b. Allow for carriage return and backspace.
c. Allow for arrow keys to edit each number.

d. Create a key that will convert the resulting image into a color image,
   each number taking on a different color.
*/

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {

    Mat M(500,500,CV_8UC1,Scalar(0));
    Rect R(0,0,20,40);

    for(;;){
        imshow("M",M);
        Mat C = M(R);
        char ch = waitKey(0);
        if (ch == 27) break;

        cout << string(1,ch) << " = " << (int)ch<< endl;
        if (ch>='0' && ch <= '9'){
            rectangle(M,R,Scalar(255));
            putText(C,string(1,ch),Point(0,12),FONT_HERSHEY_PLAIN,1,Scalar(255),1);

            if (R.x+20<M.cols) R.x+=20;
            else
            if (R.y+40<M.rows) {
                R.x=0;
                R.y+=40;
            }
            else break;
        }
        else{
            if (ch==10){
                if (R.y+40<M.rows) {
                    R.x=0;
                    R.y+=40;
                }
            }

            if (ch==8){
                if (R.x-20>=0) {
                    R.x-=20;
                }
            }
        }
    }
    return 0;
}
