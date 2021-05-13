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
//    friend Point operator+(const Point &, const Point &);
//    friend Point operator-(const Point &, const Point &);

    int m_x;
    int m_y;
    
public:
    // 构造函数
    Point(int x, int y) :m_x(x), m_y(y) {}
    
    // 拷贝构造函数 要写引用，拷贝构造函数不会出问题
    // 引用只是将point的地址值传给它，不存在新的对象，就不存在再次调用拷贝构造函数
    // 不然Point p2 = p1; 这样一直会调用拷贝构造函数
    // 加上const 增大参数的接收范围，写引用不会死循环
    Point(const Point &point) {
        m_x = point.m_x;
        m_y = point.m_y;
    }
  
    // + const Point 返回值是常量对象，不允许赋值
    // 左侧const 防止返回值被别人赋值
    // 右侧const 保证返回值又能再次调用相加 const调用const函数
    const Point operator+(const Point &point) const {
        return Point(m_x + point.m_x, m_y + point.m_y);
    }

    // - const Point 返回值是常量对象，不允许赋值
    const Point operator-(const Point &point) const {
        return Point(m_x - point.m_x, m_y - point.m_y);
    }
    
    // +=
    // 对象类型作为返回值可能会产生中间对象
    // 因为会调用拷贝构造函数，如果是引用，返回值是里面对象
    // 右侧不能添加const，因为此处要修改成员变量
    Point &operator+=(const Point &point) {
        m_x += point.m_x;
        m_y += point.m_y;
        // 返回this指向的东西，取出this指针所指向的东西
        return *this;
    }
    
    // ==
    bool operator==(const Point &point) const {
//        if (m_x == point.m_x && m_y == point.m_y) {
//            return 1;
//        } else {
//            return 0;
//        }
        return (m_x == point.m_x) && (m_y == point.m_y) ;
    }
    
    // != 右侧添加const是保证常量对象也能调用
    bool operator!=(const Point &point) const {
        return (m_x != point.m_x) && (m_y != point.m_y);
    }
    
    // - 负号 保证之前不变
    const Point operator-() {
        return Point(-m_x, -m_y);
    }
    
    // 前置++
    Point &operator++() {
        m_x++;
        m_y++;
        return *this;
    }
    
    // 后置++ 是新增int 写int就是后置
    const Point operator++(int) {
        Point oldPoint(m_x, m_y);
        m_x++;
        m_y++;
        return oldPoint;
    }
    
    // 前置--
    void operator--() {
        m_x--;
        m_y--;
    }
    
    // 后置--
    void operator--(int) {
        m_x--;
        m_y--;
    }
    
    
    void display() {
        std::cout << m_x << "   " << m_y << std::endl;
//        std::cout << m_y << std::endl;
    }
    
};


// 最好不要用Point p1 和 Point p2 因为这样会产生不必要的对象
//Point add(Point p1, Point p2) {
//    return Point(p1.m_x + p2.m_x, p1.m_y + p1.y);
//}

//Point operator+(const Point &p1, const Point &p2) {
//    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
//}
//
//Point operator-(const Point &p1, const Point &p2) {
//    return Point(p1.m_x - p2.m_x, p1.m_y - p2.m_y);
//}

int main() {
   
    Point p1(10, 20);
    Point p2(20, 30);
    Point p3(30, 40);
//    Point p4 = p1 + p2 + p3;
//    p4.display();
    
    
//    Point p5 = p3 - p2;
//    p5.display();
    
    
//    (p2+=p3) = Point(100, 100);
//    p2.display();
    
    
//    Point p6(10, 20);
//    Point p7(10, 20);
//    Point p8(10, 10);
//    std::cout << (p6 == p7) << std::endl;
//    std::cout << (p6 == p8) << std::endl;
    
    
//    Point p9 = -p1;
//    p1.display();
//    p9.display();
    
    
    // ++ 和 --
    ++p1;
    p1++;
    p1.display();
    
    --p2;
    p2--;
    p2.display();
    
    int a = 20;
    (++a) = 30; // 前置++可以被赋值，先让a的值加1，再返回a的值
//    (a++) = 30; // 后置++不可以被赋值，++在后，并不是返回a，只是将a的值放这里，然后操作完毕后，在a += 1
    
    
    Point p9(10, 20);
    // ++ 在后，先取出10,20相加得到30,60，然后将10,20和1相加
//    Point p10 = p9++ + Point(30, 40);
    // ++ 在前，先取出10,20和1相加，然后将相加结果和30, 40相加
    Point p10 = (++p9) + Point(30, 40);

    p9.display();
    p10.display();
    
    
    getchar();
    return 0;
}
