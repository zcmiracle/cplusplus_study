//
//  main.cpp
//  70-私有派生
//
//  Created by Fearless on 2021/6/26.
//

#include <iostream>
using namespace std;

class A {
public:
    int x;
private:
    int y;
protected:
    int z;
};

// 类B 私有继承 类A
class B : private A {
public:
    void print() {
        cout << x << endl;  // 类内可以访问私有继承的公开成员
        //cout << y << endl;  // 类内无法访问私有继承的私有成员
        cout << z << endl;  // 类内可以访问私有继承的保护成员
    }
};

// 类C 私有继承 类B
class C : private B {
public:
    void print1() {
        //cout << x << endl; // 类内无法访问私有继承之后转换为私有的公开成员
        //cout << y << endl; // 类内无法访问私有继承之后转换为私有的私有成员
        //cout << z << endl; // 类内无法访问私有继承之后转换为私有的保护成员
    }
};


int main() {
    
    A a;
    B b;
    
//    b.x;    // 类外无法访问私有继承之后的公开成员
//    b.y;    // 类外无法访问私有继承之后的私有成员
//    b.z;    // 类外无法访问私有继承之后的保护成员
    
    C c;
//    c.x;    // 类外无法访问私有继承之后转换为私有的公开成员
//    c.y;    // 类外无法访问私有继承之后转换为私有的私有成员
//    c.z;    // 类外无法访问私有继承之后转换为私有的保护成员
    
    getchar();
    return 0;
}
