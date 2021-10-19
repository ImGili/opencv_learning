#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
using namespace cv;

#include<iostream>
#include<sstream>

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);
    int nChannels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * nChannels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    for (i = 0; i < nRows; i++)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols; j++)
        {
            p[j] = table[p[j]];
        }
        
    }
    
    return I;
}
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << "<picture path>" << "dividWidth" << std::endl;
    }
    // 读取照片
    Mat img = imread(argv[1]);

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
        table[i] = (uchar)(dividedWidth * (i/dividedWidth));
    }
    // 处理图片，并计算处理时间
    double t = (double)getTickCount();
    ScanImageAndReduceC(img, table);
    t = ((double)getTickCount() - t)/getTickFrequency();
    std::cout << "Time passed in seconds: " << t << std::endl;

    imshow("Reduce Color Space Image Process", img);
    waitKey(0);

    return 0;
}