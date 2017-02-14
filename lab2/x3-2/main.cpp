/*x3-2
Compact matrix and vector types:

a. Using the cv::Matx33f and cv::Vec3f objects (respectively),
create a 3×3 matrix and 3-row vector.
b. Can you multiply them together directly? If not, why not?

*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Matx33f M=Matx33f::eye();
    M(0,2)=3;
    M(1,2)=4;
    cout << M << endl;
    Vec3f v(1,2,3);
    cout << v << endl;
    cout << M*v << endl;

    Matx31f N(v);
    cout << M*N << endl;

    Matx13f W(1,2,3);
    //cout << M*W << endl;//error
}
