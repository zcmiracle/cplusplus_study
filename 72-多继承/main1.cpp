//
//  main.m
//  72-多继承
//
//  Created by Fearless on 2021/6/27.
//

#include <iostream>
using namespace std;

class A{
public:
    A(int a, int b) {
        cout << "A类的构造函数" << endl;
        x1 = a;
        y1 = b;
    }
    
    void displayA() {
        cout << "x1 = " << x1 << endl;
        cout << "y1 = " << y1 << endl;
    }
    ~A() {
        cout << "A类的析构函数" << endl;
    }
private:
    int x1, y1;
};


class B {
public:
    B(int a, int b) {
        cout << "B类的构造函数" << endl;
        x2 = a;
        y2 = b;
    }
    
    void displayB() {
        cout << "x2 = " << x2 << endl;
        cout << "y2 = " << y2 << endl;
    }
    ~B() {
        cout << "B类的析构函数" << endl;
    }
private:
    int x2, y2;
};


// C类 继承 A类 和 B类
class C : public A, public B {
public:
    C(int a, int b, int c, int d, int e, int f): A(a, b), B(c, d) {
        cout << "C类的构造函数" << endl;
        x3 = e;
        y3 = f;
    }
    
    void displayC() {
        cout << "x3 = " << x3 << endl;
        cout << "y3 = " << y3 << endl;
    }
    ~C () {
        cout << "C类的析构函数" << endl;
    }
    
private:
    int x3, y3;
    
};



int Test() {

    C c(10, 20, 30, 40, 50, 60);
//    c.displayA();
//    c.displayB();
    c.displayC();
    
    getchar();
    return 0;
}
