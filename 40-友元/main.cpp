//
//  main.cpp
//  40-友元
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>
using namespace std;

/**
 友元：
 友元包括 ： 友元函数 和 友元类
 1、如果将函数 A（非成员函数）声明为类C的友元函数，那么在函数A内部就能直接访问类C对象的所有成员
 【非成员函数】不是写在类里面的函数
 2、如果将类A 声明为类C 的友元类，那么在类A 的所有成员函数内部都能直接访问类C对象的所有成员
 */

class Point {
    // 【友元函数】
    // 1、如果将函数 A（非成员函数）声明为类C的友元函数，那么在函数A内部就能直接访问类C对象的所有成员
    friend Point add(Point, Point);
    // 【友元类】 Math这个类是Point这个类的朋友
    // 2、如果将类A 声明为类C 的友元类，那么在类A 的所有成员函数内部都能直接访问类C对象的所有成员
    friend class Math;
    
private:
    int m_x;
    int m_y;
public:
    int getX() { return m_x; };
    int getY() { return m_y; };
    // 构造函数
    Point(int x, int y) :m_x(x), m_y(y) {}

    void display() {
        std::cout << m_x << std::endl;
        std::cout << m_y << std::endl;
//        std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
        getchar();
    }
};

class Math {
public:
    Point add(Point p1, Point p2) {
    //    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
        return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
    }
    // 成员函数
    void test() {
        
    }
};


// 【非成员函数】
//Point add(Point p1, Point p2) {
////    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
//    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
//}

int main() {
    
    Point p1(10, 20);
    Point p2(20, 30);
//    Point p3 = add(p1, p2);
//    p3.display();
    
    
    Point p5 = Math().add(p1, p2);
    p5.display();
    
    getchar();
    return 0;
}
