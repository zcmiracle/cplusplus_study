//
//  main.cpp
//  46-模板
//
//  Created by XFB on 2021/5/14.
//

#include <iostream>
#include "add.hpp"

using namespace std;

/**
 模板：

 泛型，是一种将【类型参数化】以达到代码复用的技术，C++中使用模板来实现泛型
 
 模板的使用格式如下：
 template <typename\class> T
 typename 和 class是等价的
 
 模板没有被使用时，是不会被实例化出来的
 
 模板的声明和实现如果分离到.h和.cpp中，会导致链接错误
 */

class Point {
    friend ostream &operator<<(ostream &, const Point &);
    int m_x;
    int m_y;
public:
    Point(int x, int y) :m_x(x), m_y(y) {}
    Point operator+(const Point &point) {
        return Point(m_x + point.m_x, m_y + point.m_y);
    }
};

ostream &operator<<(ostream &cout, const Point &point) {
    return cout << "(" << point.m_x << ", " << point.m_y << ")";
}

//int add(int a, int b) {
//    return a+b;
//}
//
//double add(double a, double b) {
//    return a + b;
//}

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {

    cout << add(10, 20) << endl;
    cout << add(1.5, 20.5) << endl;
    cout << add(Point(1, 2), Point(3, 4)) << endl;

    getchar();
    return 0;
}
