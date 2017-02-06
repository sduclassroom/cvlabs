//Example 3-2. Scalar Classes
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    Scalar_<int> A(1,2,3,4);
    Scalar_<int> B(5,6,7,8);

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * B = " << A.mul(B) << endl;
    cout << "A[1] = " << A[1] << endl;

    Scalar C(1,2,3,4.5); // double precision
    cout << "C = "<< C << endl;
    return 0;
}
