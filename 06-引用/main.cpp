//
//  main.cpp
//  06-引用
//
//  Created by XFB on 2021/4/28.
//

#include <iostream>
using namespace std;


// 值传递
//void swap(int v1, int v2) {
//    int temp = v1;
//    v1 = v2;
//    v2 = temp;
//}

// 地址传递
//void swap(int *v1, int *v2) {
//    int temp = *v1;
//    *v1 = *v2;
//    *v2 = temp;
//}

// 引用 定义两个引用
// v1 是a的别名 v2是b的别名
//void swap(int &v1 = a, int &v2 = b) {
void swap(int &v1, int &v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

// 结构体里面有int型
struct Student {
    int age;
};

// 结构体里面有指针
struct Student1 {
    int *age;
};

// 结构体里面有引用
struct Student2 {
    int &age;
};

int main() {

    int age = 10;

    // 指针
    // *p 就是age的别名
    int *p = &age;
    *p = 20;
//    cout << sizeof(p) << endl;

    // 引用
    // refAge就是age的别名，不需要使用&age，也不需要*refAge
    int &refAge = age;
    refAge = 30;
//    cout << sizeof(refAge) << endl;
    
    
//    cout << sizeof(Student) << endl; // 里面是int
//    cout << sizeof(Student1) << endl; // 里面是指针
//    cout << sizeof(Student2) << endl; // 里面是引用

//    getchar();
    return 0;
}

void test() {
    
    int age = 10;
    int height = 20;
    
    // 引用 定义一个Age的引用、refAge相当于age的别名
    int &refAge = age;
    refAge = 30; // age = 30
    refAge = height; // age = 20
    refAge += 20; // age = 40
    cout << age << endl;
    
    int &refAge1 = refAge;
    int &refAge2 = refAge1;
    
    refAge += 10;
    refAge1 += 10;
    refAge2 += 10;
    
    cout << age << endl;

    // 指针会修改指向
    int *p = &age;
    p = &height;
    // p指向一块不明白内存
    *p = 0x32da3232;
    
    int a = 10;
    int b = 20;
    
//    swap(a, b); // 值传递
//    swap(&a, &b); // 地址传递
    swap(a, b); // 引用

    cout << a << endl;
    cout << b << endl;
    
}


#if 0

// 指针
`main:
    pushq  %rbp
    movq   %rsp, %rbp
    xorl   %eax, %eax
    movl   $0x0, -0x4(%rbp)
->  movl   $0xa, -0x8(%rbp)
    leaq   -0x8(%rbp), %rcx
    movq   %rcx, -0x10(%rbp)
    movq   -0x10(%rbp), %rcx
    movl   $0x14, (%rcx) // 16 + 4 = 20
    popq   %rbp
    retq

// 引用
`main:
    pushq  %rbp
    movq   %rsp, %rbp
    xorl   %eax, %eax
    movl   $0x0, -0x4(%rbp)
->  movl   $0xa, -0x8(%rbp)
    leaq   -0x8(%rbp), %rcx
    movq   %rcx, -0x10(%rbp)
    movq   -0x10(%rbp), %rcx
    movl   $0x1e, (%rcx) // 16 + 14 = 30
    popq   %rbp
    retq

总结：综上所述，指针和引用生成的会变是一样的

#endif
