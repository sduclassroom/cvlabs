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
    const int dx=20;
    const int nx=25;
    const int dy=40;
    const int ny=10;

    uchar bgcolor = 100;
    uchar white = 255;

    Vec3b col[10] = {Vec3b(0,150,0), Vec3b(0,0,150),Vec3b(150,0,0),Vec3b(100,100,0),Vec3b(0,100,100),
                      Vec3b(100,0,100), Vec3b(150,0,150),Vec3b(125,100,0),Vec3b(0,50,100),Vec3b(0,50,0)};

    Mat M(dy*ny,dx*nx,CV_8UC1,bgcolor);

    vector<vector<char> > T(ny,vector<char>(nx,'\0'));
    //static char T[ny][nx]; // this one would also do

    Rect R(0,0,dx,dy);
    for(;;){
        rectangle(M,R,white);

        imshow("M",M);
        Mat C = M(R);
        char ch = waitKey(0);
        if (ch == 27) break;

        cout << string(1,ch) << " = " << (int)ch<< endl;
        if (ch>='0' && ch <= '9'){
            M(R)=bgcolor;
            rectangle(M,R,bgcolor);
            putText(C,string(1,ch),Point(0,dy-5),FONT_HERSHEY_PLAIN,1.5,white,1);
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
                Vec3b color(150,255,255); // yellow?
                Mat N(dy*ny,dx*nx,CV_8UC3,color);
                imshow("N",N);

            }
        }
    }
    return 0;
}
