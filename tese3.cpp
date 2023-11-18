#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(){
Mat img(512,512,CV_8UC3,Scalar(255,255,255));
circle(img,Point(256,256),155,Scalar(0,69,255),FILLED);//画圆
rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),FILLED);//画矩形
line(img,Point(130,296),Point(382,296),Scalar(255,255,255),2);//画线条
putText(img,"english",Point(137,262),FONT_HERSHEY_COMPLEX,0.75,Scalar(0,69,255),2);//文字渲染
imshow("test",img);
 waitKey(0);
    return 0;
   
}