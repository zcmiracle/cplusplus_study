//
//  main.cpp
//  01-函数重载
//
//  Created by XFB on 2021/4/27.
//

#include <iostream>

/**
 C 不支持函数重载
 C++ 支持函数重载
 */

using namespace std;

int sum(int v1, int v2) {
    return v1 + v2;
}

// 函数重载：函数名一样，但是参数个数、参数类型、参数顺序不同
int sum(int v1, int v2, int v3) {
    return v1 + v2 + v3;
}


// 函数名相同，参数顺序不一样
void func(int v1, double v2) {
    cout << "func(int v1, double v2)" << endl;
}

void func(double v1, int v2) {
    cout << "func(double v1, int v2)" << endl;
}

#if 0
// 返回值类型与函数重载无关
// 此处会直接报错，产生歧义
int func() {
    return 0;
}

double func() {
    return 0;
}
#endif


// C++编译器默认会对 符号名（函数名）进行改编、修饰
// 采用了`name mangling`或者叫`name decoration`技术

// 可能会包含参数信息，类似下面的
// display_int
void display() {
    cout << "display()" << endl;
}

void display(int a) {
    cout << "display(int) - " << a << endl;
}

// display_long
void display(long a) {
    cout << "display(long) - " << a << endl;
}

// display_double
void display(double a) {
    cout << "display(double) - " << a << endl;
}


int main(int argc, const char * argv[]) {

    cout << sum(10, 20) << endl;
    cout << sum(10, 20, 30) << endl;
    
    display();
    display(10);
    display(10L);
    display(10.5);

    func(20, 20.5);
    func(20.5, 20);
    
    getchar();
    
    return 0;
}


#if 0

// debug模式下
01-函数重载`main:
    0x100003220 <+0>:  pushq  %rbp
    0x100003221 <+1>:  movq   %rsp, %rbp
    0x100003224 <+4>:  subq   $0x10, %rsp
    0x100003228 <+8>:  movl   $0x0, -0x4(%rbp)
    
    // 0x100003100
    0x10000322f <+15>: callq  0x100003100               ; display at main.cpp:52
    0x100003234 <+20>: movl   $0xa, %edi
   
    // 0x100003130
    0x100003239 <+25>: callq  0x100003130               ; display at main.cpp:56
    0x10000323e <+30>: movl   $0xa, %edi
   
    // 0x100003180
    0x100003243 <+35>: callq  0x100003180               ; display at main.cpp:61
    0x100003248 <+40>: movsd  0xc28(%rip), %xmm0        ; xmm0 = mem[0],zero
        
    // 0x1000031d0
    0x100003250 <+48>: callq  0x1000031d0               ; display at main.cpp:66
    0x100003255 <+53>: xorl   %eax, %eax
    
    0x100003257 <+55>: addq   $0x10, %rsp
    0x10000325b <+59>: popq   %rbp
    0x10000325c <+60>: retq


optimization level

    // release 模式下，编译器优化，直接执行下面 四局代码 尴尬了
    0x1000039d0 <+0>:  pushq  %rbp
    0x1000039d1 <+1>:  movq   %rsp, %rbp
    
    // "display()"
    0x1000039d4 <+4>:  callq  0x100003744               ; display at main.cpp:52
    0x1000039d9 <+9>:  movl   $0xa, %edi

    // "display(int) - "
    0x1000039de <+14>: callq  0x1000037dc               ; display at main.cpp:56
    0x1000039e3 <+19>: movl   $0xa, %edi

    // "display(long) - "
    0x1000039e8 <+24>: callq  0x100003880               ; display at main.cpp:61
    0x1000039ed <+29>: movsd  0x4cb(%rip), %xmm0        ; xmm0 = mem[0],zero
    
    // "display(double) - "
    0x1000039f5 <+37>: callq  0x100003926               ; display at main.cpp:66
    0x1000039fa <+42>: xorl   %eax, %eax
  
    0x1000039fc <+44>: popq   %rbp
    0x1000039fd <+45>: retq

#endif
