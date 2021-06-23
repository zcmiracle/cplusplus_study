//
//  main.cpp
//  61-类的静态成员函数
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using namespace std;


int global = 100;

// 矩形
class Rectangle {

public:
    static int object;                      // 静态成员 ***
    Rectangle(double width, double height); // 有参构造函数
    double Area();                          // 矩形面积
    int compare(Rectangle rectangle);       // 面积比较函数
    
    // 静态成员函数 不能访问类的 this 指针
    static int getCount() {
        // this->Width; // this只能用于非静态成员函数内部
        // return global; 可以访问全局
        
        /**
         
         静态函数 只要使用类名 加范围解析运算符 :: 就可以访问；
         
         
         静态成员函数 只能访问静态成员数据、其他静态成员函数 和 类外部的其他函数。
         静态成员函数有一个类范围，【他们不能访问类的this指针】。您可以静态成员函数来判断类的某些对象是否已被创建。
         
         静态成员函数 与 普通成员函数的 区别：
         1、静态成员函数没有this指针，只能访问静态成员（包括静态成员变量 和 静态成员函数）
         2、普通成员函数有this指针，可以访问类中任意成员；静态成员函数没有this指针
         */
        
        return object;
    }
    
private:
    double Width;       // 矩形的宽度
    double Height;      // 矩形的高度
};


// 初始化静态成员参数
int Rectangle::object = 0;


// 有参构造函数
Rectangle::Rectangle(double width, double height) {
    cout << "我是一个有参构造函数" << endl;
    Width = width;
    Height = height;
    object ++;
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
    Rectangle rect3(20, 30);

    // 静态函数 只要使用类名 加范围解析运算符 :: 就可以访问； Rectangle::getCount()
    cout << "创建的对象个数是：" << Rectangle::getCount() << endl;
    
    getchar();
    return 0;
}
