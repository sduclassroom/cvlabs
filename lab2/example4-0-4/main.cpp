//Example 4-0-4. Cruising through array using iterator
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main(int argc, char*argv[]) {
    int sz[3] = { 4, 4, 4 };
    Mat m( 3, sz, CV_32FC3 ); // A three-dimensional array of size 4-by-4-by-4
    randu( m, -1.0f, 1.0f );  // fill with random numbers from -1.0 to 1.0


    float max2 = 0.0f;        // minimum possible value of 2D norm

    MatConstIterator_<Vec3f> it = m.begin<Vec3f>();

    // finding pixel with maximal norm, just for fun!
    while( it != m.end<Vec3f>() )
    {
        Vec3f p = *it; // p becomes the pixel iterator points to
        float norm2 = p[0]*p[0]+p[1]*p[1]+p[2]*p[2];
        if( norm2 > max2 ) max2 = norm2;
        it++;
    }

    cout << max2 << endl;
    return 0;
}
