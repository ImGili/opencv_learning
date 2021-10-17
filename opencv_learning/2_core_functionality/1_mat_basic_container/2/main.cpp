#include<iostream>
#include<opencv2/core.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));

    std::cout << "R(default) = " << std::endl << R << std::endl;
    std::cout << "R(python) = " << std::endl << format(R, Formatter::FMT_PYTHON) << std::endl;
    std::cout << "R(csv) = " << std::endl << format(R, Formatter::FMT_CSV) << std::endl;
    std::cout << "R(numpy) = " << std::endl << format(R, Formatter::FMT_NUMPY) << std::endl;
    std::cout << "R(c) = " << std::endl << format(R, Formatter::FMT_C) << std::endl;

    return 0;
}