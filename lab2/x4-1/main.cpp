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
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    int dx=20;
    int dy=40;
    int nx=25;
    int ny=20;
    Scalar bgcolor(100);
    Mat M(dx*nx,dy*ny,CV_8UC1,bgcolor);
    vector<vector<char> > T(ny,vector<char>(nx,'\0'));

    Rect R(0,0,dx,dy);
    for(;;){
        rectangle(M,R,Scalar(255));

        imshow("M",M);
        Mat C = M(R);
        char ch = waitKey(0);
        if (ch == 27) break;

        cout << string(1,ch) << " = " << (int)ch<< endl;
        if (ch>='0' && ch <= '9'){
            M(R)=bgcolor;
            rectangle(M,R,bgcolor);
            putText(C,string(1,ch),Point(0,dy-5),FONT_HERSHEY_PLAIN,1.5,Scalar(255),1);
            T[R.y/dy][R.x/dx] = ch;

            if (R.x+dx<M.cols) {
                    R.x+=dx;
            }
            else
            if (R.y+dy<M.rows) {
                R.x=0;
                R.y+=dy;
            }
            else break;
        }
        else{
            if (ch==10){
                if (R.y+dy<M.rows) {
                    rectangle(M,R,bgcolor);
                    R.x=0;
                    R.y+=dy;
                }
            }

            if (ch==8){
                if (R.x-dx>=0) {
                    M(R)=bgcolor;
                    R.x-=dx;
                    T[R.y/dy][R.x/dx] = '\0';
                    M(R)=bgcolor;
                }
            }

            if (ch=='Q'){
                if (R.x-dx>=0) {
                    rectangle(M,R,bgcolor);
                    R.x-=dx;
                }
            }

            if (ch=='S'){
                if (R.x+dx<M.cols) {
                    rectangle(M,R,bgcolor);
                    R.x+=dx;
                }
            }

            if (ch=='R'){
                if (R.y-dy>=0) {
                    rectangle(M,R,bgcolor);
                    R.y-=dy;
                }
            }

            if (ch=='T'){
                if (R.y+dy<M.rows) {
                    rectangle(M,R,bgcolor);
                    R.y+=dy;
                }
            }

            if (ch==32){
                Scalar rgb(100,100,23);
                Mat N(dy*ny,dx*nx,CV_8UC3,rgb);
                for(int i=0;i<ny;i++){
                    for(int j=0;j<nx;j++){
                        Rect R(j*dx,i*dy,dx,dy);
                        Mat C = M(R);
                        putText(C,string(1,T[i][j]),Point(0,dy-5),FONT_HERSHEY_PLAIN,1.5,Scalar(0,255,0),1);
                    }
                }

                imshow("N",N);

            }
        }
    }
    return 0;
}
