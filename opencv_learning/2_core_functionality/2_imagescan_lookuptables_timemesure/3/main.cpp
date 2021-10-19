#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << "<picture path>"
                  << "dividWidth" << std::endl;
    }
    // 读取照片
    Mat img = imread(argv[1]);
    Mat J;

    // 设置分辨率宽度
    std::stringstream s;
    int dividedWidth = 0;
    s << argv[2];
    s >> dividedWidth;
    if (!s || !dividedWidth)
    {
        std::cout << "Invalid number entered for dividing" << std::endl;
        return -1;
    }
    // 创建表
    uchar table[256];
    for (size_t i = 0; i < 256; ++i)
    {
        table[i] = (uchar)(dividedWidth * (i / dividedWidth));
    }

    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int i = 0; i < 256; ++i)
        p[i] = table[i];
    // 处理图片，并计算处理时间
    double t = (double)getTickCount();
    LUT(img, lookUpTable, J);
    t = ((double)getTickCount() - t) / getTickFrequency();
    std::cout << "Time passed in seconds: " << t << std::endl;

    imshow("Reduce Color Space Image Process", J);
    waitKey(0);

    return 0;
}