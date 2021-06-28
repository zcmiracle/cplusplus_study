//
//  main.cpp
//  75-虚函数
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;

const double PI = 3.1415926;

class Point {
public:
    Point() {
        cout << "调用Point默认的构造函数" << endl;
    }
    
    Point(int i, int j) {
        cout << "调用基类带参的构造函数" << endl;
        x = i;
        y = j;
    }
    
    // 如果不是虚函数，派生类对象地址的指针指向的是基类的成员函数
    virtual double Area() {
        cout << "Point - 1" << endl;
        return 10.0;
    }
    
private:
    int x, y;
};


class Circle : public Point {
public:
    Circle(double r) {
        cout << "调用派生类带参构造函数" << endl;
    }
    
    double Area() {
        cout << "Circle - 2" << endl;
        return PI * Radius * Radius;
    }
    
private:
    double Radius;
};
 


int main() {

    Point *point;       // 基类对象指针
    Circle circle(10.0);  // 派生类对象
    
    point = &circle;    // 派生类对象的地址 传给 基类的指针
    
    cout << "圆的面积为：" << point->Area() << endl;
    
    getchar();
    return 0;
}
