#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    int thresh = 240;//240 blue  or  200 red 
    if (thresh == 240){
    cv::VideoCapture cap("/home/aurora/视频/Infantry_blue.avi");
    while (true) {  
        Mat frame;
        cap >> frame;  
          if (frame.empty()) {
            break; 
        }
        // 分离颜色通道
        vector<Mat> channels;
        split(frame, channels);
        // 对某个颜色通道进行二值化（这里蓝色通道）
        Mat binary;
        threshold(channels[0], binary, thresh, 255, THRESH_BINARY); 
        //轮廓检测
        vector<vector<Point>>  contours;
        cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        //绘画轮廓
          std::vector<cv::RotatedRect> selectedRectangles;
            for (const auto& contour : contours) {//遍历每一个轮廓
            cv::RotatedRect minrect = cv::minAreaRect(contour);//获取轮廓的最小外接矩形
        float area = minrect.size.width * minrect.size.height;
        float longSide = max(minrect.size.width, minrect.size.height);
        float shortSide =min(minrect.size.width, minrect.size.height);
        float aspectratio= longSide / shortSide ;
           if ((aspectratio)>1 && aspectratio< 8 && area > 100) {
           selectedRectangles.push_back(minrect);
            }
            }
         vector<pair<RotatedRect, RotatedRect>> parallelPairs;
   for (size_t i = 0; i < selectedRectangles.size(); ++i) {
        for (size_t j = i + 1; j < selectedRectangles.size(); ++j) {
            float angleDiff = std::abs(selectedRectangles[i].angle - selectedRectangles[j].angle);
            float parallelAngleThreshold = 15.0; 
             float distancey = abs(selectedRectangles[i].center.y-selectedRectangles[j].center.y);
             float distancex = abs(selectedRectangles[i].center.x-selectedRectangles[j].center.x);
            if (distancex <180 && distancey <40 && distancex >30 ) {
                parallelPairs.emplace_back(selectedRectangles[i], selectedRectangles[j]);//筛选平行
            }
        }
    }
    for (const auto& pair : parallelPairs) {
   cv::Point2f vertices1[4];
        cv::Point2f vertices2[4];
        pair.first.points(vertices1);
        pair.second.points(vertices2);
        for (int i = 0; i < 4; ++i) {
            cv::line(frame, vertices1[i], vertices1[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
            cv::line(frame, vertices2[i], vertices2[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
 cv::Point2f middleCenter = (pair.first.center + pair.second.center) * 0.5;
        circle(frame,middleCenter,10, Scalar(0, 0, 255), -1);
        float longSide_0 = max(pair.first.size.width, pair.first.size.height);
         float longSide_1 = max(pair.second.size.width, pair.second.size.height);
          float longSide = max(longSide_0, longSide_1);
        float middleWidth = longSide*1.9;
        float middleHeight = longSide*1.9;
         float middleAngle = (pair.first.angle + pair.first.angle) * 0.5;
        RotatedRect middleRect (middleCenter, Size2f(middleWidth, middleHeight), middleAngle);
        cv::Point2f rectPoints[4];
        middleRect.points(rectPoints);
        for (int i =0;i<4;i++){
            line(frame,rectPoints[i],rectPoints[(i+1)% 4] ,Scalar( 0,255,0),3);
        }


        }

    }
//  vector<pair<RotatedRect,RotatedRect>> filteredPairs;
//   for (const auto& pair : parallelPairs) {
//         float minDistance = 100.0; // 最小距离阈值
//         float maxDistance = 200.0; // 最大距离阈值 
//      cv::Point2f center1 = pair.first.center; // 第一个矩形的中心点
//     cv::Point2f center2 = pair.second.center; // 第二个矩形的中心点

//     // 计算两个中心点之间的距离
//     float distance = cv::norm(center1 - center2);
//     float slope = abs((center1.y -center2.y)/(center1.x-center2.x));
//     float distancey = abs(center1.y-center2.y);
//     // 如果距离在阈值范围内，则将这对平行矩形添加到筛选列表中
//     if (distance >= minDistance && distance <= maxDistance && slope < 1 && distancey <15  ) {
//         filteredPairs.push_back(pair);//筛选距离和斜率
//     }
// }
//          for (const auto& pair :  filteredPairs){
//         cv::Point2f vertices1[4];
//         cv::Point2f vertices2[4];
//         pair.first.points(vertices1);
//         pair.second.points(vertices2);
//         for (int i = 0; i < 4; ++i) {
//             cv::line(frame, vertices1[i], vertices1[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
//             cv::line(frame, vertices2[i], vertices2[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
//         }
//             cv::Point2f middleCenter = (pair.first.center + pair.second.center) * 0.5;
//         circle(frame,middleCenter,10, Scalar(0, 0, 255), -1);
//         float longSide_0 = max(pair.first.size.width, pair.first.size.height);
//         float middleWidth = longSide_0*2.2;
//         float middleHeight = longSide_0*1.9;
//          float middleAngle = (pair.first.angle + pair.first.angle) * 0.5;
//         RotatedRect middleRect (middleCenter, Size2f(middleWidth, middleHeight), middleAngle);
//         cv::Point2f rectPoints[4];
//         middleRect.points(rectPoints);
//         for (int i =0;i<4;i++){
//             line(frame,rectPoints[i],rectPoints[(i+1)% 4] ,Scalar( 0,255,0),3);
//         }
//          }
    
     int frameRate = cap.get(CAP_PROP_FPS);
      std::string frameRateText = "FPS: " + std::to_string(frameRate);
        Size textSize = getTextSize(frameRateText, FONT_HERSHEY_SIMPLEX, 1, 2, nullptr);//文本框Size
        int textX = frame.cols - textSize.width;
        int textY = 40;
        putText(frame, frameRateText, Point(textX, textY), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
    imshow("binary",binary);
    imshow("frame",frame);
    waitKey(100);  }
    }
}