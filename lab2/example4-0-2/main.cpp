//Example 4-0-2: Ins and Outs of "Raster Scan Order"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char*argv[])
{
    Mat M(5,11,CV_8UC1);
    randu(M,Scalar(0),Scalar(100));
    Mat R3 = M.row(3);
    Mat C7 = M.col(7);

    cout << "M=" << endl << M << endl;
    cout << "M.data = " << (long) M.data << endl;
    cout << "M.step[0] = " << M.step[0] << endl;
    cout << "M.step[1] = " << M.step[1] << endl;

    cout << "R3=" << endl << R3 << endl;
    cout << "R3.data = " << (long) R3.data << endl;
    cout << "R3.step[0] = " << R3.step[0] << endl;
    cout << "R3.step[1] = " << R3.step[1] << endl;

    cout << "C7=" << endl << C7 << endl;
    cout << "C7.data = " << (long) C7.data << endl;
    cout << "C7.step[0] = " << C7.step[0] << endl;
    cout << "C7.step[1] = " << C7.step[1] << endl;


    cout << "R3.data - M.data = " << (long) R3.data - (long) M.data << endl;
    cout << "C7.data - M.data = " << (long) C7.data - (long) M.data << endl;
    return 0;
}
