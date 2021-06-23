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


int Rectangle::object = 0;      // 初始化静态成员参数

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


/**
 static
 static 关键字把类成员定义为静态的，当我们声明类的成员为静态时，意味着无论创建多少个类的对象，静态成员都只有一个副本
 
 静态成员在类的所有对象是共享的。
 在创建第一个对象时，所有的静态数据都会被初始化为0
 不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符号 :: 来重新声明静态变量
 从而对它进行初始化，
 
 */

int main() {
    
    Rectangle rect1(10, 20);
    Rectangle rect2(15, 15);
    
    cout << "创建的对象个数是："<< rect1.object << endl;
//    cout << "创建的对象个数是："<< rect2.object << endl;

    getchar();
    return 0;
}
