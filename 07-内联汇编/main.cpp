//
//  main.cpp
//  07-内联汇编
//
//  Created by XFB on 2021/4/29.
//

#include <iostream>
using namespace std;


int sum(int a, int b) {
    return a + b;
}

int main() {

    // 内联汇编
//    int a = 10;
//    asm {
//        mov eax, 20
//    }
    
    int c = sum(1, 2);
    
//    cout << c << endl;
    
//    int a = 10;
//    int b = 20;
//    
//    if (a == b) {
//        printf("111111");
//    } else {
//        printf("222222");
//    }
        
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





int c = sum(1, 2);

07-内联汇编`main:

    // 入栈
    0x100003f80 <+0>:  pushq  %rbp
    // rbp = rsp  rsp赋值给rbp
    0x100003f81 <+1>:  movq   %rsp, %rbp
    // 16字节  rsp 减去 16字节
    0x100003f84 <+4>:  subq   $0x10, %rsp
    
    0x100003f88 <+8>:  movl   $0x0, -0x4(%rbp)
    // edi = 1 变址寄存器 主要用于存放存储单元在段内的偏移量
    0x100003f8f <+15>: movl   $0x1, %edi
    // esi = 2 变址寄存器 主要用于存放存储单元在段内的偏移量
    0x100003f94 <+20>: movl   $0x2, %esi
    // sum()
    0x100003f99 <+25>: callq  0x100003f60               ; sum at main.cpp:12

    // ecx = ecx ^ ecx
    0x100003f9e <+30>: xorl   %ecx, %ecx
    // 函数返回值
    0x100003fa0 <+32>: movl   %eax, -0x8(%rbp)
    // 将ecx赋值给eax ECX 是计数器(counter), 是重复(REP)前缀指令和LOOP指令的内定计数器。
    0x100003fa3 <+35>: movl   %ecx, %eax

    // 栈平衡
    0x100003fa5 <+37>: addq   $0x10, %rsp
    0x100003fa9 <+41>: popq   %rbp
    0x100003faa <+42>: retq


4个数据寄存器(EAX、EBX、ECX、EDX)
2个变址和指针寄存器(ESI、EDI)
2个指针寄存器(ESP、EBP)

栈的最常见操作有两种：Push（入栈）和Pop（出栈）。

ESI、EDI
它们主要用于存放存储单元在段内的偏移量，用它们可实现多种存储器操作数的寻址方式，为以不同的地址形式访问存储单元提供方便。
变址寄存器不可分割成8位寄存器。作为通用寄存器，也可存储算术逻辑运算的操作数和运算结果。
它们可作一般的存储器指针使用。在字符串操作指令的执行过程中，对它们有特定的要求，而且还具有特殊的功能。


ESP(rsp)：栈指针寄存器，其内存放着一个指针，该指针永远指向系统栈最上面一个栈帧的栈顶。
EBP(rbp)：基址指针寄存器，其内存放着一个指针，该指针永远指向系统栈最上面一个栈帧的底部。

#endif
