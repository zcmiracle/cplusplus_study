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
    int a = 10;
    asm {
        mov eax, 20
    }
    
//    int c = sum(1, 2);
//    cout << c << endl;

    
//    int a = 10;
//    int b = 20;
//    
//    if (a == b) {
//        printf("111111");
//    } else {
//        printf("222222");
//    }
    
    
//    int a = 1;
//    int b = 2;
//    int c = a + b;
    
   
//    int age = 2;
//    int *p = &age;
//    *p = 3;
   
    
    
    // 引用补充
//    int age= 20;
//    int *p1 = &age;
//    int *&ref1 = p1;
//    *ref1 = 30;
//    int height = 30;
//    ref1 = &height;
    
//    int array[] = {1, 2, 3};
//    int (&ref)[3] = array;

//    int *p;
//    // 指针数组，数组里面可以存放3个 int *
//    int *arr1[3] = {p, p, p};
//    // 用于指向数组的指针，指向存放int元素的数组，而且有3个
//    int (*arr2)[3];
//        
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

07-内联汇编`main:
    0x100003f90 <+0>:  pushq  %rbp
    0x100003f91 <+1>:  movq   %rsp, %rbp
    0x100003f94 <+4>:  xorl   %eax, %eax

    // 将0寄存器赋值给【rbp-0x4】所在的存储空间
    0x100003f96 <+6>:  movl   $0x0, -0x4(%rbp)
    // 将1赋值给【rbp - 0x8】地址所在的存储空间 a = 1
    0x100003f9d <+13>: movl   $0x1, -0x8(%rbp)
    // 将2赋值给【rbp - 0xc】地址所在的存储空间 b = 2
    0x100003fa4 <+20>: movl   $0x2, -0xc(%rbp)

    // 将【rbp-0x8】地址所在存储空间的值赋值给ecx 将a 赋值给ecx
    0x100003fab <+27>: movl   -0x8(%rbp), %ecx
    // 将【rbp-0xc】地址所在存储空间的值取出 + ecx 也就是b的值 和 ecx也就是a的值相加
    0x100003fae <+30>: addl   -0xc(%rbp), %ecx
    0x100003fb1 <+33>: movl   %ecx, -0x10(%rbp)
    0x100003fb4 <+36>: popq   %rbp
    0x100003fb5 <+37>: retq




07-内联汇编`main:
    0x100003f90 <+0>:  pushq  %rbp
    0x100003f91 <+1>:  movq   %rsp, %rbp
    // 按位异或，相同的位置为0，不同的位置为1，eax和eax每一位都相同，所以相当于清零
    // 将寄存器eax设置为0即 movl $0, %eax
    // 使用objdump 对比发现xorl的版本只需要2个字节，而用movl的版本需要5个字节
    // 运用了x^x = 0的这一属性
    0x100003f94 <+4>:  xorl   %eax, %eax


    // 把rbp栈帧指针减去4个字节的起始地址后的4字节的内存初始化为0
    0x100003f96 <+6>:  movl   $0x0, -0x4(%rbp)

    // 将堆栈指针减去8个字节的起始地址后的4字节的内存的值初始化为2
    0x100003f9d <+13>: movl   $0x2, -0x8(%rbp)

    // rcx保存栈底减去算好需要的空间字节
->  0x100003fa4 <+20>: leaq   -0x8(%rbp), %rcx

    // 将rcx地址所在存储空间的值赋值给【rbp-0x10】地址所在的存储空间
    0x100003fa8 <+24>: movq   %rcx, -0x10(%rbp)

    // 将rbp-0x10 地址所在存储空间的值赋值给rcx
    0x100003fac <+28>: movq   -0x10(%rbp), %rcx

    // 将3赋值给rcx地址所在的存储空间
    0x100003fb0 <+32>: movl   $0x3, (%rcx)

    // 栈平衡
    0x100003fb6 <+38>: popq   %rbp
    0x100003fb7 <+39>: retq


#endif
