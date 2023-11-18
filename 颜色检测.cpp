#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
 Mat img,imgHSV,mask;
  int hmin =0, smin =0, vmin =0;
 int hmax = 179, smax = 255, vmax = 255;

    //  img = imread("/home/aurora/图片/123.png");
    VideoCapture cap ("/home/aurora/视频/Infantry_blue.avi");
         namedWindow("TrackBars",(640,240));
     createTrackbar("Hue min","TrackBars",&hmin,179);
     createTrackbar("Hue max","TrackBars",&hmax,179);
     createTrackbar("Sat min","TrackBars",&smin,255);
     createTrackbar("Sat max","TrackBars",&smax,255);
     createTrackbar("Val min","TrackBars",&vmin,255);
     createTrackbar("Val max","TrackBars",&vmax,255);
    
    while(1){
         cap.read(img);
     cvtColor(img,imgHSV,COLOR_BGR2HSV);

     Scalar lower(hmin,smin,vmin);
     Scalar upper(hmax,smax,vmax);
     inRange(imgHSV,lower,upper,mask);
     imshow("test",img);
     imshow("test HSV",imgHSV);
     imshow("test Mask",mask);
     waitKey(1000);
    }
return 0;
}