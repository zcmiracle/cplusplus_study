//
//  main.cpp
//  24-构造函数的互相调用
//
//  Created by XFB on 2021/5/10.
//

#include <iostream>

/**
 构造函数调用构造函数不能直接调用，只能放在初始化列表中
 
 */

struct Person {
  
    int m_age;
    int m_height;
    
    // 无参构造函数
//    Person(): Person(10, 20) {
//
//    }
    
    Person() {
        // 报错，构造函数不能直接调用构造函数
        // 想当创建了一个person对象，并且在栈空间，是一个全新的对象。并将10，20赋值给了age和height
        // 赋值给了一个临时的person对象
        Person(10, 20);
    }
    
    // 有参构造函数
    Person(int age, int height) {
        this->m_age = age;
        this->m_height = height;
    }
};


int main() {

    Person person;
    
//    std::cout << person.m_age << std::endl;
//    std::cout << person.m_height << std::endl;

    getchar();
    return 0;
}



#if 0
Person(): Person(10, 20) {

}

24-构造函数的互相调用`Person::Person:
    0x100003f10 <+0>:  pushq  %rbp
    0x100003f11 <+1>:  movq   %rsp, %rbp
    // Person person;
    0x100003f14 <+4>:  subq   $0x10, %rsp

    0x100003f18 <+8>:  movq   %rdi, -0x8(%rbp)
    0x100003f1c <+12>: movq   -0x8(%rbp), %rdi

    0x100003f20 <+16>: movl   $0xa, %esi //     = 10
    0x100003f25 <+21>: movl   $0x14, %edx // edx = 20
    0x100003f2a <+26>: callq  0x100003f40               ; Person::Person at main.cpp:32
    0x100003f2f <+31>: addq   $0x10, %rsp
    0x100003f33 <+35>: popq   %rbp
    0x100003f34 <+36>: retq



Person() {
    // 报错，构造函数不能直接调用构造函数
    // 想当创建了一个person对象，并且在栈空间，是一个全新的对象。并将10，20赋值给了age和height
    Person(10, 20);
}

24-构造函数的互相调用`Person::Person:
    0x100003f40 <+0>:  pushq  %rbp
    0x100003f41 <+1>:  movq   %rsp, %rbp
    0x100003f44 <+4>:  subq   $0x10, %rsp
    0x100003f48 <+8>:  movq   %rdi, -0x8(%rbp)

    0x100003f4c <+12>: movl   %esi, -0xc(%rbp)
    0x100003f4f <+15>: movl   %edx, -0x10(%rbp)

    0x100003f52 <+18>: movq   -0x8(%rbp), %rdi
    0x100003f56 <+22>: movl   -0xc(%rbp), %esi
    0x100003f59 <+25>: movl   -0x10(%rbp), %edx
    0x100003f5c <+28>: callq  0x100003f70               ; Person::Person at main.cpp:32
    0x100003f61 <+33>: addq   $0x10, %rsp
    0x100003f65 <+37>: popq   %rbp
    0x100003f66 <+38>: retq


#endif

