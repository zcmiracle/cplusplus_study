//
//  main.cpp
//  71-保护派生
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
class B : protected A {
public:
    void print() {
        cout << x << endl;  // 类内可以访问保护继承的公开成员(转为保护)
        //cout << y << endl;  // 类内无法访问保护继承的私有成员(不变)
        cout << z << endl;  // 类内可以访问私有继承的保护成员(不变)
    }
};

//  类C 私有继承 B
class C : protected B {
public:
    void print1() {
        cout << x << endl;  // 类内可以访问保护继承的保护成员(不变)
        //cout << y << endl;  // 类内无法访问保护继承之后的私有成员(不变)
        cout << z << endl;  // 类内可以访问保护继承之后的保护成员(不变)
    }
private:
    
};


int main() {

    A a;
    B b;
//    b.x;    // 类外无法访问保护成员
//    b.y;    // 类外无法访问私有成员
//    b.z;    // 类外无法访问保护成员
    
    C c;
//    c.x;    // 类外无法访问保护成员
//    c.y;    // 类外可以访问私有成员
//    c.z;    // 类外无法访问保护成员12345
    
    
    
    
    getchar();
    return 0;
}
