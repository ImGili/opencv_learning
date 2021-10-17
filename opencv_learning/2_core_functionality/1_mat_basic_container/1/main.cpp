#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;
// 各种创建Mat的方法
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

    Mat C0 = ((Mat_<double>(3, 3)) << 0 , -1 , 0 , -1 , 5 , -1 , 0 , -1 , 0); 
    Mat C1 = (Mat_<double>({0 , -1 , 0 , -1 , 5 , -1 , 0 , -1 , 0}).reshape(3));
    std::cout << "C0 = " << std::endl << C0 << std::endl;
    std::cout << "C1 = " << std::endl << C1 << std::endl;

    Mat raw1C0 = C0.row(1).clone();
    std::cout << "raw1C0 = " << std::endl << raw1C0 << std::endl;

    Mat R(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));
    std::cout << "R = " << std::endl << R << std::endl;

    imshow("R", R);
    waitKey(0);

    return 0;
}