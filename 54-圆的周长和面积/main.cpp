//
//  main.cpp
//  54-圆的周长和面积
//
//  Created by Fearless on 2021/6/21.
//

#include <iostream>
using namespace std;

class Circle {
    double radius;
public:
    double get_radius(double r) {
        return radius = r;
    }
    
    // 周长
    double get_girth() {
        return 2 * 3.14 * radius;
    }
    
    // 面积
    double get_area() {
        return 3.14 * radius * radius;
    }
};

void test () {
    // 面向过程
    // r半径 girth周长 area面积
    double r = 0, girth, area;
    const double PI = 3.14;
    
    cin >> r;
    // 周长
    girth = 2 * PI * r;
    // 面积
    area = PI * r * r;
    
    cout << "周长:" << girth << endl;
    cout << "面积:" << area << endl;

    getchar();
}

// 继承
class Bay: Circle {
    
};

int main() {
    
    Circle A, B, C, D;
    
    cout << "A圆的半径：" << A.get_radius(5) << endl;
    cout << "A圆的周长：" << A.get_girth() << endl;
    cout << "A圆的面积：" << A.get_area() << endl;
   
    cout << "------------" << endl;

    cout << "B圆的半径：" << B.get_radius(20) << endl;
    cout << "B圆的周长：" << B.get_girth() << endl;
    cout << "B圆的面积：" << B.get_area() << endl;
   
    cout << "------------" << endl;
    
    cout << "C圆的半径：" << C.get_radius(100) << endl;
    cout << "C圆的周长：" << C.get_girth() << endl;
    cout << "C圆的面积：" << C.get_area() << endl;
    
    cout << "------------" << endl;
    
    double radius;
    cout << "等待键盘输入:" << endl;
    cin >> radius;
    D.get_radius(radius);
    cout << "D圆的周长：" << D.get_girth() << endl;
    cout << "D圆的面积：" << D.get_area() << endl;
    
    
    Bay E;
//    E.get_girth()
    
    
    return 0;
}
