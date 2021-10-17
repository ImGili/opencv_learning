#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>
using namespace cv;
int main(int argc, char* argv[] )
{
    std::string image_path = samples::findFile(argv[1]);
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read image :" << image_path << std::endl;
        return -1;
    }
    imshow("Display image", img);
    int k = waitKey(0);

    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    
    return 0;
}