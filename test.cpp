#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat img;
    img = imread("/home/aurora/图片/test.jpeg");//告诉地址 读取
Mat imgGary,imgBlur,imgCanny,imgDia,imgErode;
cvtColor(img,imgGary,COLOR_BGR2GRAY);//变灰
GaussianBlur(img,imgBlur,Size(7,7),5,0);//模糊
Canny(imgBlur,imgCanny,25,50);//边缘处理
Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
dilate(imgCanny,imgDia,kernel);//图像膨胀
erode(imgDia,imgErode,kernel);//图像侵蚀
imshow("TESTgARY",imgGary);
imshow("TESTBlur",imgBlur);
imshow("TESTgCanny",imgCanny);
imshow("TESTgDia",imgDia);
imshow("TESTgErode",imgErode);
    waitKey(0);
    }

    //    VideoCapture cap(0);
//    Mat img;
//    while (1){
//     cap.read(img);
//     imshow("test",img);//展示
//     waitKey(5);
    