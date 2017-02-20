//Example 4-0-3: Accessing Elements using at<>() and ptr<>()
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[])
{
    Mat m = Mat::eye(5,5,CV_32FC1);
    randu(m,-10.0,10.0);
    cout << "m="<<endl;
    cout << m << endl;
    cout << "Element m(3,3) is " << m.at<float>(3,3) << endl;

    cout << "Element m(2,3) is " << m.ptr<float>(2)[3] << endl;

    Mat n = Mat::eye(5,5,CV_32FC2);
    randu(n,-10.0,10.0);
    cout << "n="<<endl;
    cout << n << endl;
    cout << "Element n(3,3) is " << n.at<Vec2f>(3,3) << endl;
    cout << "Element n(2,3) is " << n.ptr<Vec2f>(2)[3] << endl;


    return 0;
}
