//
//  main.cpp
//  62-指向类的指针
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


int main() {

    Rectangle rect1(10, 20);
    Rectangle rect2(15, 15);
    Rectangle *R;               // 定义指向类的指针
   
    R = &rect1;                 // 获取对象rect1的地址，用指针访问成员函数
    cout << "第一个矩形的面积是：" << R->Area() << endl;
    
    R = &rect2;                 // 获取对象rect2的地址，用指针访问成员函数
    cout << "第二个矩形的面积是：" << R->Area() << endl;

    getchar();
    return 0;
}
