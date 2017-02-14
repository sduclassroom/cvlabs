/*
x3-3.
Compact matrix and vector template types:
a. Using the cv::Mat<> and cv::Vec<> templates (respectively),
create a 3x3 matrix and 3-row vector.
b. Can you multiply them together directly? If not, why not?
c. Try type-casting the vector object V to a 3x1 matrix, using the cv::Mat<> template.
What happens now?
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    //a
    Matx<int,3,3> M(1,2,3,4,5,6,7,8,9);
    Vec<int,3> V(1,2,3);
    cout << M << endl;
    cout << V << endl;
    //b
    cout << M*V << endl;
    //c
    cout << (Matx<int,3,1>)V << endl;
    cout << M*(Matx<int,3,1>)V << endl;
}
