//
//  main.cpp
//  65-缺省构造函数
//
//  Created by XFB on 2021/6/24.
//

#include <iostream>
using namespace std;

class B {
    float x, y;
public:
    
    B() {                   // 默认缺省构造函数
        x = 0;
        y = 0;
        cout << "初始化静态局部对象\n";
    }
    
    B(float a) {            // 一个参数的构造函数
        x = a;
        y = 0;
        cout << "初始化全局对象\n";
    }
    
    B(float a, float b) {   // 两个参数的构造函数
        x = a;
        y = b;
        cout << "初始化自动局部对象\n";
    }
 
    void Print(void) {      // 成员函数
        cout << x << "\t" << y << endl;
    }
    
};


B b0(100.0);    // 初始化全局对象

void C(void) {
    cout << "进入C()函数\n";
    B b2(1, 2);             // 初始化自动局部对象
    static B b3;            // 初始化静态局部对象
}


// ===============================================================
class A {
    int x, y;
public:
    A(int a) {              // 构造函数1
        x = a;
        cout << "1\n";
    }
    A(int a, int b) {       // 构造函数2
        x = a, y = b;
        cout << "2\n";
    }
};
 
A a1(3);                    // 全局对象（在main函数执行之前 调用构造函数）

// 全局的f 函数
void f(void) {
    A b(2, 3);
}
// ===============================================================

int main() {

//    A a2(4, 5);
//    f();
//    f();
    
    cout << "进入main函数\n";
    
    B b1(3.0, 7.0); // 初始化自动局部对象
    C();            // 进入C()函数  初始化自动局部对象  初始化静态局部对象
    C();            // 进入C()函数  初始化自动局部对象
    
    getchar();
    return 0;
}
