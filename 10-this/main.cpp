//
//  main.cpp
//  10-this
//
//  Created by XFB on 2021/5/7.
//

#include <iostream>
using namespace std;

struct Person {
    int m_id;
    int m_age;
    int m_height;
    
    void display() {
        // eax == &person.m_age == &person + 4
        // mov eax, dword ptr [this]
        // [eax]、[eax + 4]、[eax + 8]
        // [&person + 4]、[&person + 4 + 4]、[&person + 4 + 8]
        cout << "id = " << m_id
            << ", age = " << m_age
            << ", height = " << m_height << endl;
    }
};

int main() {

    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    
    
    Person *p = (Person *) &person.m_age;
    p->m_id = 40;
    p->m_age = 50;
    
    // id = 40, age = 50, height = 0
    p->display();

    // 将person对象的地址传递给display函数的this
    // person.display();
    
    // 将指针p里面的存储的地址传递给display函数的this
    // 将&person.m_age传递给display函数的this
    
    getchar();
    return 0;
}


void test() {
    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    person.display();

    Person *p = &person;
    p->m_id = 10;
    p->m_age = 20;
    p->m_height = 30;
    person.display();
}


#if 0

10-this`main:
    
Person person;
person.m_id = 10;
person.m_age = 20;
person.m_height = 30;

汇编如下：

    // 首先将调用函数的栈底压栈到自己函数的栈中 pushq %rbp
    0x100003f90 <+0>:  pushq  %rbp
    // 然后将原来函数栈顶rsp作为当前函数的栈底 movq %rsp, %rbp
    0x100003f91 <+1>:  movq   %rsp, %rbp
    // 按位异或，相同的位置为0，不同的位置为1，eax和eax每一位都相同，所以相当于清零
    // 将寄存器eax设置为0即 movl $0, %eax
    // 使用objdump 对比发现xorl的版本只需要2个字节，而用movl的版本需要5个字节
    // 运用了x^x = 0的这一属性
    0x100003f94 <+4>:  xorl   %eax, %eax

    // 把rbp栈帧指针减去4个字节的起始地址后的4字节的内存初始化为0
    0x100003f96 <+6>:  movl   $0x0, -0x4(%rbp)
    // 将rbp栈帧指针减去16字节的起始位置后的4字节的内存初始化为10
    // person.m_id = 10;
    0x100003f9d <+13>: movl   $0xa, -0x10(%rbp)
    // 将rbp栈帧指针减去12字节的起始位置后的4字节的内存初始化为20
    // person.m_age = 20;
    0x100003fa4 <+20>: movl   $0x14, -0xc(%rbp)
    // 将rbp栈帧指针减去8字节的起始位置后的4字节的内存初始化为30
    // person.m_height = 30;
    0x100003fab <+27>: movl   $0x1e, -0x8(%rbp)

    // 函数运行完成时，会将压入栈中的rbp重新出栈到rbp中（popq %rbp）
    0x100003fb2 <+34>: popq   %rbp
    0x100003fb3 <+35>: retq



Person person;
Person *p = &person;
p->m_id = 10;
p->m_age = 20;
p->m_height = 30;

汇编如下：

    0x100003f80 <+0>:  pushq  %rbp
    0x100003f81 <+1>:  movq   %rsp, %rbp
    // movl $0, %eax
    0x100003f84 <+4>:  xorl   %eax, %eax
    // 把rbp栈帧指针减去4个字节的起始地址后的4字节的内存初始化为0
    0x100003f86 <+6>:  movl   $0x0, -0x4(%rbp)

// 下面两句是将person对象的地址值放到指针变量所在的存储空间
// Person *p = &person;
    // 将【rbp-0x10】将栈帧指针减去16个字节的起始地址 赋值给寄存器 rcx
    // 【rbp-0x10】 是person对象的地址
    0x100003f8d <+13>: leaq   -0x10(%rbp), %rcx
    // 将person对象的地址 放到【rbp-0x18】这个地址所在的存储空间
    // 【rbp-0x18】是指针变量p的地址
    0x100003f91 <+17>: movq   %rcx, -0x18(%rbp)

    // 寄存器 rcx 存储的是person对象的地址
    // rbp-0x18】是指针变量p的地址，这里将指针变量p所在存储空间的内容取出来赋值给 rcx
    // 也就是person对象的地址
    0x100003f95 <+21>: movq   -0x18(%rbp), %rcx
    // 给person对象首地址所在的存储空间赋值（4个字节的数据）
    // person->m_id = 10
    0x100003f99 <+25>: movl   $0xa, (%rcx)
    // 同上 person->m_age = 20
    0x100003f9f <+31>: movq   -0x18(%rbp), %rcx
    // 将20赋值给rcx + 4 偏移4个字节地址所在存储空间
    0x100003fa3 <+35>: movl   $0x14, 0x4(%rcx)
    // 同上 person->m_height = 30
    0x100003faa <+42>: movq   -0x18(%rbp), %rcx
    0x100003fae <+46>: movl   $0x1e, 0x8(%rcx)


// 原理：如何利用指针间接访问所指向对象的成员变量？
1、从指针中取出对象的地址
2、利用对象的地址 + 成员变量的偏移量计算出成员变量的地址
3、根据成员变量的地址访问成员变量的存储空间

    // 函数运行完成时，会将压入栈中的rbp重新出栈到rbp中（popq %rbp）
    0x100003fb5 <+53>: popq   %rbp
    0x100003fb6 <+54>: retq


#endif
