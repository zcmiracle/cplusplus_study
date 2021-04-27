//
//  main.cpp
//  02-默认参数
//
//  Created by XFB on 2021/4/27.
//

#include <iostream>

using namespace std;


//int sum(int v1, int v2) {
//    return v1 + v2;
//}

//int sum(int v1 = 10, int v2 = 5) {
//    return v1 + v2;
//}

// 默认参数 必须从右往左开始
//int sum(int v1, int v2 = 5) {
//    return v1 + v2;
//}

// 错误
//int sum(int v1 = 10, int v2) {
//    return v1 + v2;
//}

// 函数声明
//int sum(int v1 = 10, int v2 = 20);

//int age = 20;
//// 函数声明 默认参数只能放 字面量 or 全局变量 or 函数名
//int sum(int v1 = 10, int v2 = age);

void test(int a) {
    cout << "test(int) - " << a <<endl;
}

// 默认参数的值可以是常量、全局符号(全局变量、函数名)
// C语言也可以将函数名作为参数传递，只是没有默认参数
void func(int v1, void(*p)(int) = test) {
    p(v1);
}


// 函数重载、函数名相同，参数个数不同，第一个有默认参数。最好保留第一个
void display1(int a, int b = 20) {
    cout << "a is " << a << endl;
}

void display1(int a) {
    cout << "a is " << a << endl;
}


int sum1(int v1, int v2) {
    return v1 + v2;
}

int main() {

 
    sum1(1, 2);
    sum1(3, 4);

    
    
    // display1 可以调用上面2个方法，有二义性
//    display1(5);
    
//    func(30);
//    func(20, test);
    
//    cout << sum() << endl; // 10 + 5
//    cout << sum(20) << endl; // 20 + 5
//    cout << sum(10, 20) << endl; // 10 + 20

//    getchar();
    return 0;
}

//int sum(int v1, int v2) {
//    return v1 + v2;
//}

#if 0

02-默认参数`main:
    0x1000032a0 <+0>:  pushq  %rbp
    0x1000032a1 <+1>:  movq   %rsp, %rbp
    0x1000032a4 <+4>:  subq   $0x10, %rsp
    0x1000032a8 <+8>:  movl   $0x0, -0x4(%rbp)

    0x1000032af <+15>: movl   $0x1, %edi
    0x1000032b4 <+20>: movl   $0x2, %esi
    0x1000032b9 <+25>: callq  0x100003280               ; sum1 at main.cpp:59

    0x1000032be <+30>: movl   $0x3, %edi
    0x1000032c3 <+35>: movl   $0x4, %esi
    0x1000032c8 <+40>: movl   %eax, -0x8(%rbp)
    0x1000032cb <+43>: callq  0x100003280               ; sum1 at main.cpp:59
    
    0x1000032d0 <+48>: xorl   %ecx, %ecx
    0x1000032d2 <+50>: movl   %eax, -0xc(%rbp)
    0x1000032d5 <+53>: movl   %ecx, %eax
    0x1000032d7 <+55>: addq   $0x10, %rsp
    0x1000032db <+59>: popq   %rbp
    0x1000032dc <+60>: retq


#endif
