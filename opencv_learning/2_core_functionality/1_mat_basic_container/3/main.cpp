#include<iostream>
#include<vector>
#include<opencv2/core.hpp>
using namespace cv;
int main(int argc, char** argv )
{

    Point2f P(5, 1);
    std::cout << P << std::endl;

    Point3f P3f(2, 6, 7);
    std::cout << P3f << std::endl;

    std::vector<float> v;
    v.push_back( (float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
    std::cout << Mat(v) << std::endl;

    std::vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); i++)
    {
        vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    }
    std::cout << "A vector of 2D Points = " << vPoints << std::endl << std::endl;
    return 0;
}