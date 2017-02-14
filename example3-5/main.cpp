//Example 3-5. Template Classes
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {

    Point_<int> P(1,2);
    Rect_<int> R(1,2,10,20);
    Vec<int,5> V;
    Matx<int,3,4> M;
    Scalar_<int> S;

    cout << "P = " << P << endl;
    cout << "R = " << R << endl;
    cout << "V = " << V << endl;
    cout << "M = " << endl << M << endl;
    cout << "S = " << S << endl;


    typedef Point_<float> Nukte; // creating alias for Point_<float>
    Nukte N(3,4);
    cout << "N = " << N << endl;
    return 0;
}
