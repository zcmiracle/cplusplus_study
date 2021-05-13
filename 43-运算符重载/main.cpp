//
//  main.cpp
//  43-运算符重载
//
//  Created by Fearless on 2021/5/12.
//

#include <iostream>

class Point {
    // 友元函数
//    friend Point operator+(Point, Point);
    // 最好用const并且使用引用类型 const可以接受const和非const
    // 引用类型是为了不产生中间对象或者说不产生临时对象因为 Point p1
    friend Point operator+(const Point &, const Point &);
    int m_x;
    int m_y;
    
public:
    // 构造函数
    Point(int x, int y) :m_x(x), m_y(y) {}
    
    void display() {
//        std::cout << "x = " << m_x << std::endl;
//        std::cout << "y = " << m_y << std::endl;
        getchar();
    }
};

// 最好不要用Point p1 和 Point p2 因为这样会产生不必要的对象
//Point add(Point p1, Point p2) {
//    return Point(p1.m_x + p2.m_x, p1.m_y + p1.y);
//}


Point operator+(const Point &p1, const Point &p2) {
    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}


int main() {
   
    Point p1(10, 20);
    Point p2(20, 30);
    Point p3(30, 40);
    
    Point p4 = p1 + p2 + p3;
    p4.display();
    
    getchar();
    return 0;
}
