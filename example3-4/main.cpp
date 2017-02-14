//Example 3-4. Fixed Matrix Classes
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char*argv[]) {
    Matx33f A=Matx33f::ones();
    A(2,2) = 5; A(1,1) = 3;
    cout << "A = " << endl << A << endl;
    cout << "A.t() = " << endl << A.t() << endl;
    cout << "A.inv() = " << endl << A.inv() << endl;
    cout << "A.row(2) = " << endl << A.row(2) << endl;
    cout << "A.diag() = " << endl << A.diag() << endl;
    Matx31f B(1,2,3);
    cout << "B = " << endl << B << endl;
    cout << "AX=B, X = " << endl << A.solve(B,0)<< endl;
    return 0;
}
