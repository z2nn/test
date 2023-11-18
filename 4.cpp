#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
 vector<int> myColors{18,25,100,255,95,255};


 void findColor(Mat img){
    Mat imgHSV,mask;
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    Scalar lower(18,100,95);
    Scalar upper(25,255,255);
    inRange(imgHSV,lower,upper,mask);
    imshow("orange1",mask);
 }
int main() {
    VideoCapture cap("/home/aurora/视频/orange1.mp4"); 
    Mat img;
    while (true) {
        cap.read(img);
        Mat imgHSV,mask;
          if (img.empty()) {
            break; 
        }
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    Scalar lower(18,100,95);
    Scalar upper(25,255,255);
    inRange(imgHSV,lower,upper,mask);
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));//这行代码创建了一个椭圆形的内核（核心），该内核用于形态学操作。
        morphologyEx(mask, mask, MORPH_CLOSE, kernel);//：这行代码使用形态学闭合操作将掩码图像 mask 进行处理。形态学闭合操作有助于消除图像中的小孔和空洞，以及连接接近的对象区域。kernel 是上面创建的椭圆形内核。
        vector<vector<Point>> contours;//定义了一个二维向量 contours，用于存储图像中找到的轮廓。
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//：这行代码查找二值化掩码图像 mask 中的轮廓。findContours 函数的参数包括输入图像、存储轮廓的向量 contours、轮廓的检索方式（RETR_EXTERNAL 表示只检索最外层轮廓）、以及轮廓的近似方法（CHAIN_APPROX_SIMPLE 表示仅保留轮廓的关键点，以节省内存）。这个函数会将找到的轮廓保存在 contours 向量中，以便后续处理。
        for ( auto contour : contours) {
            if (contourArea(contour) > 100) { 
               
                Point2f center;
                float radius;
                minEnclosingCircle(contour, center, radius);
                circle(img, center, radius, Scalar(0, 255, 0), 2);
            }
        }
    imshow("orange1",img);
    waitKey(1000 /cap.get(CAP_PROP_FPS));
        }
    return 0;
}
