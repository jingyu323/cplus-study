#pragma comment(lib, "opencv_world490.lib")
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std; 
using namespace cv;

int main() {
    Mat srcImage = imread("card2.png");
    // // if (!srcImage.data) {
    // //     std::cout << "Image not loaded";
    // //     return -1;
    // // }
    // // imshow("image", srcImage);
    // waitKey(0); 

    cout << "Hello World"; 
    return 0;
}
