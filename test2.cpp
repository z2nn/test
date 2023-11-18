#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
     Mat img,imgResize,imgCrop;
    img = imread("/home/aurora/图片/test.jpeg");//告诉地址 读取
    cout<<img.size()<<endl;
    resize(img,imgResize,Size(),0.8,0.8);//改大小
    Rect roi(300,300,300,400);//起点坐标，宽高
    imgCrop=img(roi);//裁减
    imshow("test",img);
imshow("test2",imgResize);
imshow("test3",imgCrop);
    waitKey(0);
}
