//
//  main.cpp
//  63-动态内存技术
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using  namespace std;

/**
 堆：在函数内部声明的所有变量都将占有栈内存。
 栈：这是程序中未使用的内存，在程序运行时可用于动态分配内存。
 
 如果不需要动态分配的内存空间，可以使用 delete 运算符
 删除之前 由 new 运算符分配的内存。
 
 */

int main() {

    int *name = NULL;   // 初始化
    name = new int;     // 申请内存空间
    delete name;        // 释放name申请的内存空间

    
    int *p1 = new int[10];  // 为p1申请内存空间
    delete[] p1;            // 释放p1的内存空间
    

    // 二维数据动态分配
    // 第一个维度的长度 m，第二个维度的长度 n
    int m = 3, n = 4;
    int **p2;
    p2 = new int*[m]; // 指向数组的指针 int * 是指针， []是数组
    
    for (int i = 0; i < m; i ++) {
        p2[i] = new int[n];
        cout << *p2[i] << endl;
    }
    
    for (int i = 0; i < m; i ++) {
        delete[] p2[i];
    }

    
    string s1;
    string s2 = "fearless";
    s1 = s2;
    
    // C语言中 字符串拷贝传递 strcpy 字符串有 \0
    // C++ 可以直接赋值，字符串没有\0
    cout << s1 << endl;
    
    
    string s3(3, 'A');
    cout << "s3的内容是：" << s3 << endl;

    string s4 = "my name is miracle.";
    int length = s4.length();
    cout << "s4字符串的长度为：" << length << endl;
    
    getchar();
    return 0;
}
