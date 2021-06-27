//
//  main.cpp
//  72-多继承
//
//  Created by Fearless on 2021/6/27.
//

#include <iostream>
using namespace std;

class Base1 {
    int x;
public:
    Base1(int a) {
        x = a;
        cout << "调用基类1的构造函数" << endl;
    }
    ~Base1() {
        cout << "调用基类1的析构函数" << endl;
    }
};

class Base2 {
    int y;
public:
    Base2(int a) {
        y = a;
        cout << "调用基类2的构造函数" << endl;
    }
    ~Base2() {
        cout << "调用基类2的析构函数" << endl;
    }
};

// 先调用base2的构造函数 ，再去调用base1的构造函数  这里是基类的构造函数
class Derived: public Base2, public Base1 {
    int z;
    Base1 b1, b2; // 这是对象成员，有对象成员，先构造，在基类构造函数后
public:
    Derived(int a, int b) : Base1(a), Base2(20), b1(100), b2(a + b) {
        z = b;
        cout << "调用派生类的构造函数" << endl;
    }
    
    ~Derived() {
        cout << "调用派生类的析构函数" << endl;
    }
};



int main() {
    
    Derived c(100, 200);
    
    return 0;
}
