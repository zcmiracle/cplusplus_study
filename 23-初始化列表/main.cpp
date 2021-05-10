//
//  main.cpp
//  23-初始化列表
//
//  Created by XFB on 2021/5/10.
//

#include <iostream>


/**
 特点：
 一种便捷的初始化成员变量的方式
 只能用在构造函数中
 初始化顺序只跟成员变量的【声明顺序有关】

 
 初始化列表与默认参数配合使用
 1、如果函数声明和实现是分离的
 初始化列表只能写在函数的实现中
 默认参数只能写在函数的声明中
 
 */

struct Person {
    int m_age;
    int m_height;

    // 常规构造方法
//    Person(int age, int height) {
//        m_age = age;
//        m_height = height;
//    }

    // 初始化列表 和上面效率一样 因为生产的汇编都是一样的
//    Person(int age, int height) :m_age(age), m_height(height) {}
    // 语法糖
//    Person(int age = 0, int height = 0) :m_age(age), m_height(height) {}
    // 换行 精简
    Person(int age = 0, int height = 0)
        :m_age(age), m_height(height) {}

    
};


int myAge() { return 10; }
int myHeight() { return  100; }

struct Student {
    int m_age;
    int m_height;
    
    // 因为即使传入 20和200，也只是赋值给了age 和 height，后面是 myAge赋值给m_age
    // 并不是 age 赋值给 m_age
    Student(int age, int height) : m_age(myAge()), m_height(myHeight()) {
        
    }
};



struct GoodStudent {
    int m_age;
    int m_height;
    // 函数声明，并且函数的默认参数必须写在函数声明中
//    GoodStudent(int age, int height);

    GoodStudent(int age = 0, int height = 0);
};

// 函数实现 后面 :m_age(age), m_height(height) 是初始化列表
GoodStudent::GoodStudent(int age, int height) : m_age(age), m_height(height) { }
// 会报错，因为函数的默认参数不能写在函数的实现中，只能写在函数的声明中
//GoodStudent::GoodStudent(int age = 0, int height = 0) : m_age(age), m_height(height) { }


int main() {

//    Person person(20, 130);
//    std::cout << person.m_age << std::endl;
//    std::cout << person.m_height << std::endl;
    
    Student student(20, 200);
    std::cout << student.m_age << std::endl;
    std::cout << student.m_height << std::endl;
        
    getchar();
    return 0;
}


#if 0

Person(int age, int height) {
    m_age = age;
    m_height = height;
}

23-初始化列表`Person::Person:
    0x100003f90 <+0>:  pushq  %rbp
    0x100003f91 <+1>:  movq   %rsp, %rbp
    0x100003f94 <+4>:  movq   %rdi, -0x8(%rbp)
    0x100003f98 <+8>:  movl   %esi, -0xc(%rbp)
    0x100003f9b <+11>: movl   %edx, -0x10(%rbp)
    0x100003f9e <+14>: movq   -0x8(%rbp), %rax
    0x100003fa2 <+18>: movl   -0xc(%rbp), %ecx
    0x100003fa5 <+21>: movl   %ecx, (%rax)
    0x100003fa7 <+23>: movl   -0x10(%rbp), %ecx
    0x100003faa <+26>: movl   %ecx, 0x4(%rax)
    0x100003fad <+29>: popq   %rbp
    0x100003fae <+30>: retq




Person(int age, int height) :m_age(age), m_height(height) {

}

23-初始化列表`Person::Person:
    0x100003f90 <+0>:  pushq  %rbp
    0x100003f91 <+1>:  movq   %rsp, %rbp
    0x100003f94 <+4>:  movq   %rdi, -0x8(%rbp)
    0x100003f98 <+8>:  movl   %esi, -0xc(%rbp)
    0x100003f9b <+11>: movl   %edx, -0x10(%rbp)
    0x100003f9e <+14>: movq   -0x8(%rbp), %rax
    0x100003fa2 <+18>: movl   -0xc(%rbp), %ecx
    0x100003fa5 <+21>: movl   %ecx, (%rax)
    0x100003fa7 <+23>: movl   -0x10(%rbp), %ecx
    0x100003faa <+26>: movl   %ecx, 0x4(%rax)
    0x100003fad <+29>: popq   %rbp
    0x100003fae <+30>: retq


#endif
