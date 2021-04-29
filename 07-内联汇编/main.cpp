//
//  main.cpp
//  07-内联汇编
//
//  Created by XFB on 2021/4/29.
//

#include <iostream>
using namespace std;

int main() {

    // 内联汇编
//    int a = 10;
//    asm {
//        mov eax, 20
//    }
    
    int a = 10;
    int b = 20;
    
    if (a == b) {
        printf("111111");
    } else {
        printf("222222");
    }
        
    
    return 0;
}


#if 0

07-内联汇编`main:
    0x100003f30 <+0>:  pushq  %rbp
    0x100003f31 <+1>:  movq   %rsp, %rbp
    // 拉伸16字节 rsp = rsp - 16
    0x100003f34 <+4>:  subq   $0x10, %rsp

    // 将0x0也就是 0赋值给地址为【rbp-0x4】的内存的值
    0x100003f38 <+8>:  movl   $0x0, -0x4(%rbp)

    // int a = 10
    // 将变量0xa也就是10，赋值给地址为【rbp-0x8】的内存地址
    0x100003f3f <+15>: movl   $0xa, -0x8(%rbp)
    // int b = 20
    // 将0x14也就是20，赋值给地址为【rbp-0xc】的内存地址
    0x100003f46 <+22>: movl   $0x14, -0xc(%rbp)

    // 将地址为【rbp-0x8】的内存地址所对应的值 赋值给寄存器 eax
    0x100003f4d <+29>: movl   -0x8(%rbp), %eax


    // 比较地址为【rbp-0xc】对应的值【b的值】 和 eax【a的值】是否相等
    0x100003f50 <+32>: cmpl   -0xc(%rbp), %eax
    // 跳转指令：jne：带条件跳转，jump not equal 比较结果不相等才跳转
    0x100003f53 <+35>: jne    0x100003f6c               ; <+60> at main.cpp:25:9


// ====================== 相等 ====================== //
    // 将地址为【rip + 0x42】的内存地址 赋值给 寄存器rdi
    0x100003f59 <+41>: leaq   0x42(%rip), %rdi          ; "111111"
    0x100003f60 <+48>: movb   $0x0, %al
    0x100003f62 <+50>: callq  0x100003f82               ; symbol stub for: printf
    // 如果不想等执行到这里，直接跳过下面三局代码
    0x100003f67 <+55>: jmp    0x100003f7a               ; <+74> at main.cpp
// ====================== 相等 ====================== //



// ====================== 【不相等】 ====================== //
    // 不相等 【0x100003f6c】直接跳这里，上面四局代码不执行
    0x100003f6c <+60>: leaq   0x36(%rip), %rdi          ; "222222"
    0x100003f73 <+67>: movb   $0x0, %al
    0x100003f75 <+69>: callq  0x100003f82               ; symbol stub for: printf
// ====================== 【不相等】 ====================== //


    // 最后不管条件 a 和 b 是否相等，都会执行到这里
    0x100003f7a <+74>: xorl   %eax, %eax
    0x100003f7c <+76>: addq   $0x10, %rsp
    0x100003f80 <+80>: popq   %rbp
    0x100003f81 <+81>: retq


汇编规则：
1、操作数长度
    + movl %eax, %edx
    其中l是操作数长度
b = byte(8-bit)
s = short(16-bit integer or 32-bit floating point)
w = word(16-bit)
l = long(32-bit integer or 64-bit floating point)
q = quad(64-bit)
t = ten bytes(80-bit foating point)

#endif
