//
//  main.cpp
//  11-类与对象
//
//  Created by XFB on 2021/5/7.
//

#include <iostream>
using namespace std;

struct Person {
    // 成员变量属性
    int m_age;
    
    // 成员函数方法
    void run() {
        cout << "Person::run() - " << m_age << endl;
    }
};


class Car {
    
public:
    int m_price;
    void run() {
        cout << "Car::run() " << m_price << endl;
    }
};


int main() {

    Car car1;
    car1.m_price = 10;
    car1.run(); // call函数地址
    
    Car car2;
    car2.m_price = 20;
    car2.run();
    
    Car car3;
    car3.m_price = 30;
    car3.run();
    
    
    getchar();
    return 0;
}

#if 0

11-类与对象`main:
    0x100003160 <+0>:  pushq  %rbp
    0x100003161 <+1>:  movq   %rsp, %rbp
    0x100003164 <+4>:  subq   $0x20, %rsp
    0x100003168 <+8>:  movl   $0x0, -0x4(%rbp)
    0x10000316f <+15>: movl   $0xa, -0x8(%rbp)
    0x100003176 <+22>: leaq   -0x8(%rbp), %rdi
    // callq  0x1000031c0
    0x10000317a <+26>: callq  0x1000031c0               ; Car::run at main.cpp:26
    0x10000317f <+31>: movl   $0x14, -0x10(%rbp)
    0x100003186 <+38>: leaq   -0x10(%rbp), %rdi
    // callq  0x1000031c0
    0x10000318a <+42>: callq  0x1000031c0               ; Car::run at main.cpp:26
    0x10000318f <+47>: movl   $0x1e, -0x18(%rbp)
    0x100003196 <+54>: leaq   -0x18(%rbp), %rdi
    // callq  0x1000031c0
    0x10000319a <+58>: callq  0x1000031c0               ; Car::run at main.cpp:26
    0x10000319f <+63>: callq  0x100003e16               ; symbol stub for: getchar
    0x1000031a4 <+68>: xorl   %ecx, %ecx
    0x1000031a6 <+70>: movl   %eax, -0x1c(%rbp)
    0x1000031a9 <+73>: movl   %ecx, %eax
    0x1000031ab <+75>: addq   $0x20, %rsp
    0x1000031af <+79>: popq   %rbp
    0x1000031b0 <+80>: retq


#endif
