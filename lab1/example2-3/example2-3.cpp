//Example 2-3. A simple OpenCV program for playing a video file from disk
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
int main( int argc, char** argv )
{
    cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture cap;
    cap.open(argv[1]);
    cv::Mat frame;
    for(;;)
    {
        cap >> frame;
        if(frame.empty()){
                break; // ran out of film
        }
        cv::imshow("Example3",frame);
        char ch = cv::waitKey(33);
        if (ch > 0) {
                break;
        }
    }
    return 0;
}
