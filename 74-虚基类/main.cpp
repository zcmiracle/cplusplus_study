//
//  main.cpp
//  74-虚基类
//
//  Created by Fearless on 2021/6/27.
//

#include <iostream>
using namespace std;

/**
 虚基类：为了解决多继承的 命名冲突 和 冗余问题，C++提出了虚基类，使得在派生类中只保留一份间接基类的成员。
 在继承方式前面加上 virtual 关键字就是虚继承
 */

class A {
protected:
    int m_a;
};

class B: virtual public A {
protected:
    int m_b;
};

class C: virtual public A {
protected:
    int m_c;
};

class D: public B, public C {
public:
    void setA(int a) {
        m_a = a;
    }
    
    void setB(int b) {
        m_b = b;
    }
    
    void setC(int c) {
        m_c = c;
    }
    
    void setD(int d) {
        m_d = d;
    }
    
private:
    int m_d;
};


int main() {

    D d;
    
    getchar();
    return 0;
}
