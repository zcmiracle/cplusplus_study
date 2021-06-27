//
//  main.cpp
//  73-多继承的冲突
//
//  Created by Fearless on 2021/6/27.
//

#include <iostream>
using namespace std;

class A {
public:
    int x;
private:
  
};

class B {
public:
    int x;
private:
    
};

class C: public A, public B {
public:
    int x = 30;
private:
    
};



// =============== 基类与对象成员 ===============


class Dot { // 基类
public:
    double x, y;
    Dot(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
    
    void ShowDot() {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
private:
};

// Line 继承基类Dot
class Line: public Dot {
public:
    Line(Dot dot1, Dot dot2) : d1(dot1), d2(dot2) {
        x = (d1.x + d2.x) / 2;
        y = (d1.y + d2.y) / 2;
    }
    void ShowLine() {
        cout << "Dot1：" << endl;
        d1.ShowDot();
        cout << "Dot2：" << endl;
        d2.ShowDot();
        // 开根号
        cout << sqrt((d1.x-d2.x)*(d1.x-d2.x) + (d1.y-d2.y)*(d1.y-d2.y)) << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
private:
    Dot d1, d2;
};


int main(void) {
 
//    C c1;
//    // 删除C类中的int x
//    // Member 'x' found in multiple base classes of different types
//    // 当派生类中新增加的数据或函数与基类中原有的同名时，若不加限制，则优先调用派生类中的成员。
//    cout << c1.x << endl;

    
    double a, b;
    cout << "请输入Dot1的x和y坐标";
    cin >> a >> b;
    
    Dot dot1(a, b);
    
    cout << "请输入Dot2的x和y坐标";
    cin >> a >> b;
    Dot dot2(a, b);
    
    
    Line line(dot1, dot2);
    line.ShowLine();
    
    getchar();
    return 0;
}
