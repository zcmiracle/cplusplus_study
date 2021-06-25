//
//  main.cpp
//  68-保护派生
//
//  Created by XFB on 2021/6/25.
//

#include <iostream>

using namespace std;


class S {
public:
    S(int x, int y) {
        a = x;
        b = y;
    }
    
    void print() {
        cout << a << endl;
        cout << b << endl;
    }
    
    ~S() {
        cout << "调用S析构函数" << endl;
    }

private:
//    int a, b;
protected:
    int a, b;

};

class Z : public S {
public:
    
    // 一定要加上 :S(x, y)
    // Z是继承自S，是派生类，需要加上基类的构造函数
    // 派生类中 不能定义基类的对象 **** 重点 ****
    Z(int x, int y) : S(x, y) {
        // a = x;  // 'a' is a private member of 'S'
        // b = y;  // 'b' is a private member of 'S'
    }
    
    ~Z() {
        cout << "调用Z的析构函数" << endl;
    }
private:
    
};






// ===========================================
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
    
    
    S s1(1, 3);
    s1.print();
    
    Z z1(3, 5);
    z1.print();
    
    getchar();
    return 0;
}
