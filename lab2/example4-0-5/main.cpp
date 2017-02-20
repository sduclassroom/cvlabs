//Example 4-0-5. Saturation Casting
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    uchar x = 10;
    cout << "auto-casting to int :" << (x-128)*2+128 << endl;
    cout << "C++ casting to uchar, (then to int, to see the value): "
    << (int)(uchar)((x-128)*2+128) << endl;

    uchar y = saturate_cast<uchar>((x-128)*2+128);
    cout << "saturation casting to uchar, (then to int, to see the value): "
    << (int) y << endl;

    float f = 33333.333;
    cout << "saturation casting from float to short: "
    <<saturate_cast<short>(f) << endl;
    cout << "C++ casting from float to short: "
    <<(short)f << endl;
    return 0;
}
