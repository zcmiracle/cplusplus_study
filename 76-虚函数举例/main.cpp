//
//  main.cpp
//  76-虚函数举例
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;


class A {
public:
    A() {
        cout << "调用基类A的构造函数" << endl;
        x = 1000;
    }
//    void PrintData() {
//        cout << "X的值为：" << x << endl;
//    }
    
    // 基类成员函数 声明为虚函数，派生类只能引用从基类继承来的成员
    virtual void PrintData() {
        cout << "X的值为：" << x << endl;
    }
    
private:
    int x;
};

class B : public A {
public:
    B() {
        cout << "调用派生类B的构造函数" << endl;
        y = 2000;
    }
    void PrintData() {
        cout << "Y的值为：" << y << endl;
    }
private:
    int y;
};


class C : public A {
public:
    C() {
        cout << "调用派生类C的构造函数" << endl;
        z = 3000;
    }
    
    void PrintData() {
        cout << "Z的值为：" << z << endl;
    }
    
private:
    int z;
};

int main() {

    A *p;
    A a;
    B b;
    C c;
    
    a.PrintData();
    b.PrintData();
    c.PrintData();
    
    p = &a;
    p->PrintData();
    p = &b;
    p->PrintData();
    p = &c;
    p->PrintData();

    getchar();
    return 0;
}
