#include<iostream>
#include<opencv2/core.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    std::cout << "M = " << std::endl << M << std::endl;

    M.create(4,4, CV_8UC(2));
    std::cout << "M = " << std::endl << M << std::endl;

    Mat E = Mat::eye(4, 4, CV_64F);
    Mat O = Mat::ones(2, 2, CV_32F);
    Mat Z = Mat::zeros(3, 3, CV_8UC1);
    std::cout << "E = " << std::endl << E << std::endl;
    std::cout << "O = " << std::endl << O << std::endl;
    std::cout << "Z = " << std::endl << Z << std::endl;

    return 0;
}