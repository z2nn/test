#include <opencv2/opencv.hpp>
#include<vector>
using namespace cv;
using namespace std;

const int cellNumber = 20; 
const int cellSize = 30; 

class Snake {
public:
    Snake();
    int score=0;
    void move(char direction);//移动
    void makeFood();//生成食物
    bool checkCollision();//检查碰撞
    bool checkBoundary();//检查边界
    void draw(Mat& gamemap);//绘制地图
    vector<Point> body;
    Point food;
    char currentDirection;
};

Snake::Snake() {
    Point priminalHead(cellNumber / 2, cellNumber / 2);
    Point priminalBody((priminalHead.x-1,priminalHead.y-1));
    body.push_back(priminalHead);
    body.push_back(priminalBody);
    makeFood();
    currentDirection = 'd'; 
}

void Snake::move(char direction) {
    // 移动
    switch(direction){
case 'w' :
if(currentDirection != 's'){
    currentDirection = 'w'; break;
}
case 's' :
if(currentDirection != 'w'){
    currentDirection = 's'; break;
}
case 'a' :
if(currentDirection != 'd'){
    currentDirection = 'a'; break;
}
case 'd' :
if(currentDirection != 'a'){
    currentDirection = 'd'; break;
}
    }
    Point newHead = body.front();
switch(currentDirection){
    case 'w' :
    newHead.y--;break;
    case 'a' :
    newHead.x--;break;
    case 's' :
    newHead.y++;break;
    case 'd' :
    newHead.x++;break;
}
body.insert(body.begin(),newHead);
if(newHead == food){
       score++; 
       makeFood();
}
else{
    body.pop_back();
}
}

void Snake::makeFood() {
    // 生成随机食物
    do{
        food.x=rand()%cellNumber;
        food.y=rand()%cellNumber;
    }while(find(body.begin(), body.end(), food) != body.end());//vector中find()查找并返回迭代器 范围左闭右开
}

bool Snake::checkCollision() {
    // 检查是否碰撞，1/0
    Point head = body.front();
    return count(body.begin() + 1, body.end(), head) > 0;//vector中count()返回这个值出现的次数,从第二个部位开始数
    
}

bool Snake::checkBoundary() {
    // 检查是否超出边界，1/0
    Point head = body.front();
    return head.x < 0 || head.x >= cellNumber || head.y < 0 || head.y >= cellNumber;
}

void Snake::draw(Mat& gamemap) {
    // 地图
        for (int i = 0; i < cellNumber; i++) {
        for (int j = 0; j < cellNumber; j++) {
            rectangle(gamemap, Point(i * cellSize, j * cellSize), Point((i + 1) * cellSize, (j + 1) * cellSize), Scalar(255, 255, 255), 1);
        }
    }
    // 蛇身
        for ( Point segment : body) { //基于范围的for循环 (c++11),第一部分是范围内用于迭代的变量，第二部分则表示被迭代的范围。
            rectangle(gamemap, Point(segment.x * cellSize, segment.y * cellSize), Point((segment.x + 1) * cellSize, (segment.y + 1) * cellSize), Scalar(255, 0, 0), FILLED);
    }
    //食物
        rectangle(gamemap, Point(food.x * cellSize, food.y * cellSize), Point((food.x + 1) * cellSize, (food.y + 1) * cellSize), Scalar(0, 0, 255), FILLED);
}
int main() {
    Mat gamemap(cellNumber * cellSize, cellNumber * cellSize, CV_8UC3,Scalar(0,0,0));
    Snake snake;
       while (1) {
        char key = waitKey(150);
        if (key == 27) break; 
        snake.move(key);
        if (snake.checkCollision() || snake.checkBoundary()) break;
        gamemap = Scalar(0, 0, 0);
        putText(gamemap,"scores : " + to_string(snake.score), Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 1);
        snake.draw(gamemap);
        imshow("贪吃蛇游戏", gamemap);
    }
    putText(gamemap,"game over !",Point((cellNumber / 5)*cellSize, (cellNumber / 2.5)*cellSize),FONT_HERSHEY_SIMPLEX, 2.2, Scalar(255, 255, 255),4.5);
    putText(gamemap, "scores : " + to_string(snake.score), Point((cellNumber / 3.9)*cellSize, (cellNumber / 1.6)*cellSize), FONT_HERSHEY_SIMPLEX, 1.6, Scalar(255, 255, 255),4.5);
    imshow("贪吃蛇游戏", gamemap);
    waitKey(0);
    return 0;
}
