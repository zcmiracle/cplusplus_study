//
//  main.cpp
//  60-类的静态成员static
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using namespace std;

// 矩形
class Rectangle {

public:
    static int object;                      // 静态成员 ***
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


int main() {

    return 0;
}
