//
//  main.cpp
//  69-公有派生
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

// 类B 公开继承 类A public
class B: public A {
public:
    void print() {
        cout << x << endl;  // 类内可以访问公开继承的公开成员
        // cout << y << endl;  // 类内无法访问公开继承的私有成员
        cout << z << endl;  // 类内可以访问公开继承的保护成员
    }
};


int main() {

    A a;
    B b;
    b.x; // 类外可以访问公开继承的公开成员
    //b.y; // 类外无法访问公开继承的私有成员
    //b.z; // 类外无法访问公开继承的保护成员

    getchar();
    return 0;
}
