#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
    // Mat img;
    // img = imread("/home/aurora/图片/test.jpeg");//告诉地址 读取
    // if(img.empty()){
    //     cout<<"请确认文件是否存在"<<endl;
    //     return -1;
    // }
    // Mat B;
    // img.copyTo(B);
    // imshow("test",img);//展示
    // imshow("test2",B);
    // waitKey(0);


   
   VideoCapture cap("/home/aurora/视频/贪吃蛇演示视频.mp4");
   Mat img;
   while (1){
    cap.read(img);
    imshow("test",img);//展示
    waitKey(20);
   }
}
//?读取摄像头
    //    VideoCapture cap(0);
//    Mat img;
//    while (1){
//     cap.read(img);
//     imshow("test",img);//展示
//     waitKey(5);
    