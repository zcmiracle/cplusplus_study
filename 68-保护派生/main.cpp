//
//  main.cpp
//  68-保护派生
//
//  Created by XFB on 2021/6/25.
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

class B: protected A {
public:
    void print() {
        cout << x << endl;  // 类内可以访问 保护继承的公开成员（转为保护）
        // cout << y << endl;
        cout << z << endl;  // 类内可以访问 私有继承的保护成员
    }
};

class C : protected B {
public:
    void print1() {
        cout << x << endl;
        // cout << y << endl;
        cout << z << endl;
    }
};

int main() {

    B b;
    b.print();
    
//    b.x;
//    b.z;
    
    C c;
//    c.print1();    
    
    getchar();
    return 0;
}
