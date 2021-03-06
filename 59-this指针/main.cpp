//
//  main.cpp
//  59-this指针
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using namespace std;

// 矩形
class Rectangle {

public:
    Rectangle(double width, double height); // 有参构造函数
    double Area();                          // 矩形面积
    int compare(Rectangle rectangle);       // 面积比较函数
    
private:
    double Width;       // 矩形的宽度
    double Height;      // 矩形的高度
};

// 有参构造函数
Rectangle::Rectangle(double width, double height) {
    cout << "我是一个有参构造函数" << endl;
    Width = width;
    Height = height;
}

// 矩形的面积
double Rectangle::Area() {
    return Width * Height;
}

// 矩形面积的比较
int Rectangle::compare(Rectangle rectangle) {
    double max;
    max = this->Area() > rectangle.Area() ? this->Area() : rectangle.Area();
    return max;
}

// ---------- 内联函数 ----------
inline int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    Rectangle rect1(10, 20);
    Rectangle rect2(15, 15);
    cout << "矩形最大的面积是：" << rect1.compare(rect2) << endl;
    
    // ---------- 内联函数 ----------
    cout << "Max(10, 20)的最大值是：" << Max(10, 20) << endl;
    cout << "Max(100, 120)的最大值是：" << Max(100, 120) << endl;
    cout << "Max(300, 200)的最大值是：" << Max(300, 200) << endl;

    
    
    getchar();
    return 0;
}
