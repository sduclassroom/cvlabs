//Example 3-1. Point Classes
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char*argv[]) {
    Point p1(1,2);
    Point p2(2,3);
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1.y = " << " " << p1.y << endl;
    cout << "p2.x = " << " " << p2.x << endl;
    cout << "p1 * p2 = " << p1.dot(p2) << endl;
    cout << "p1 + p2 = " << p1+p2 << endl;

    Point3i p3(1,2,3);
    Point3i p4(4,5,6);
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;
    cout << "p3 x p4 = " << p3.cross(p4) << endl;
    cout << "p3 * p4 = " << p3.dot(p4) << endl;

    return 0;
}
