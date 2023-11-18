#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
        Mat russianFlag(600, 900, CV_8UC3, Scalar(255, 255, 255));
    int stripeHeight = russianFlag.rows / 3;

    Mat blueStripe(stripeHeight, russianFlag.cols, CV_8UC3);
    blueStripe.setTo(Scalar(186, 81,0));
    Rect blueRect(0, stripeHeight, russianFlag.cols, stripeHeight);
    blueStripe.copyTo(russianFlag(blueRect));


    Mat redStripe(stripeHeight, russianFlag.cols, CV_8UC3);
    redStripe.setTo(Scalar(5, 30, 216));
    Rect redRect(0, 2*stripeHeight, russianFlag.cols, stripeHeight);
    redStripe.copyTo(russianFlag(redRect));
    
    imshow("Russian Flag", russianFlag);
    waitKey(0);
   
    Mat ukFlag(500, 1000, CV_8UC3, Scalar(255, 255, 255));
    rectangle(ukFlag,Point(0,0),Point(1000,500),Scalar(105,33,1),FILLED);//blue bottom
    line(ukFlag, Point(0, 0), Point(1000,500), cv::Scalar(255, 255, 255), 100);//white line*2
    line(ukFlag, Point(1000, 0), Point(0,500), cv::Scalar(255, 255, 255), 100);
    line(ukFlag, Point(0, 17), Point(500,270), cv::Scalar(46,16,200), 33);//red line*4
    line(ukFlag, Point(17, 500), Point(500,270), cv::Scalar(46,16,200), 33);
    line(ukFlag, Point(983, 0), Point(500,230), cv::Scalar(46,16,200), 33);
    line(ukFlag, Point(1000, 483), Point(500,230), cv::Scalar(46,16,200), 33);
    rectangle(ukFlag,Point(0,166.667),Point(1000,333.333),Scalar(255,255,255),FILLED);//white rect*2
    rectangle(ukFlag,Point(416.667,0),Point(583.333,500),Scalar(255,255,255),FILLED);
rectangle(ukFlag,Point(0,0.4*ukFlag.rows),Point(ukFlag.cols,0.6*ukFlag.rows),Scalar(46,16,200),FILLED);//red rect*2
rectangle(ukFlag,Point(0.45*ukFlag.cols,0),Point(0.55*ukFlag.cols,ukFlag.rows),Scalar(46,16,200),FILLED);    
imshow("ukFalg",ukFlag);
waitKey(0);
    return 0;
}
