#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Shape {
public:
    virtual double area() = 0;
};
class Circle : public Shape {
public:
    double r;
    double area() {
        return (M_PI * r * r);
    }
};
class Rectangle : public Shape {
public:
    double a, b;
    double area() {
        return (a * b);
    }
};
class Triangle : public Shape {
public:
    double a, b, c;
    double p, s;
    double area() {
        p = (a + b + c)/2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        return(s);
    }
};
int main() {
    int n;
    cin >> n;
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
    vector<double>area;
   
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << fixed << setprecision(2);
        if ((name.compare("Circle"))==0){
            cin >>circle.r;
            area.push_back(circle.area());
        }
        if ((name.compare("Rectangle")) == 0) {
            cin >> rectangle.a >> rectangle.b;
            area.push_back(rectangle.area());
        }
        if ((name.compare("Triangle")) == 0) {
            cin >> triangle.a >> triangle.b >> triangle.c;
            area.push_back(triangle.area());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << area[i] << endl;
    }
    return 0;
}