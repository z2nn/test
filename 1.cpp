#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
    //视频
       VideoCapture cap("/home/aurora/视频/飞翔的橘子识别示例视频.mp4");
   Mat img;
   int frameRate = cap.get(CAP_PROP_FPS);
   while (1){
    cap>>img;
          if (!cap.read(img)) {
            break;  
        }
    std::string frameRateText = "FPS: " + std::to_string(frameRate);
        Size textSize = getTextSize(frameRateText, FONT_HERSHEY_SIMPLEX, 1, 2, nullptr);//文本框Size
        int textX = img.cols - textSize.width;
        int textY = 40;
        putText(img, frameRateText, Point(textX, textY), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        //文字渲染函数
    imshow("test",img);
    waitKey(1000 /cap.get(CAP_PROP_FPS));}
    //摄像头
       VideoCapture cap1(0);
       Mat img1;
       while  (1){
        cap1>>img1;
        int frameRate1 = cap1.get(CAP_PROP_FPS);
        std::string frameRateText = "FPS: " + std::to_string(frameRate1);
        Size textSize = getTextSize(frameRateText, FONT_HERSHEY_SIMPLEX, 1, 2, nullptr);
        int textX = img1.cols - textSize.width ;
        int textY = 40;
        putText(img1, frameRateText, Point(textX, textY),FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        imshow("text2",img1);
        waitKey(1);

       }
       
        return 0;


}