#include<iostream>
#include<sstream>
#include<vector>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);
    int channels = I.channels();
    int nRows = I.rows;
    int nCols = I.cols * channels;
    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int i,j;
    uchar* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}

int main(int argc, char** argv )
{
    // 读取图像
    std::string image_path = samples::findFile(argv[1]);
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read image :" << image_path << std::endl;
        return -1;
    }

    // 制作查询表格
    int divideWith = 0; // convert our input string to number - C++ style
    std::stringstream s;
    s << argv[2];
    s >> divideWith;
    if (!s || !divideWith)
    {
        std::cout << "Invalid number entered for dividing. " << std::endl;
        return -1;
    }
    uchar table[256];
    for (int i = 0; i < 256; ++i)
       table[i] = (uchar)(divideWith * (i/divideWith));

    // 计算时间
    double t = (double)getTickCount();
    // do something ...
    ScanImageAndReduceC(img, table);
    t = ((double)getTickCount() - t)/getTickFrequency();
    std::cout << "Times passed in seconds: " << t << std::endl;

    imshow("Display image", img);
    int k = waitKey(0);
    return 0;
}