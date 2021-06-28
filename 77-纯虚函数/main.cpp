//
//  main.cpp
//  77-纯虚函数
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;


class A {
public:
    virtual void display() = 0;     // 申明纯虚函数
protected:
    int x;
};

class B: public A {
public:
    B() {
        cout << "调用派生类B的构造函数" << endl;
        y = 2000;
    }
    
    void display() {
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
    
    void display() {
        cout << "Z的值为：" << z << endl;
    }
    
private:
    int z;
};

int main() {

//    A a;    // 至少包含一个纯虚函数的类是抽象类，不能创建对象，只能派生新的类。
    A *p;
    B b;
    C c;
    
    p = &b;
    p->display();
    
    
    p = &c;
    p->display();
    
    getchar();
    return 0;
}
