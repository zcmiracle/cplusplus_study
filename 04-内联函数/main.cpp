//
//  main.cpp
//  04-内联函数
//
//  Created by XFB on 2021/4/28.
//

#include <iostream>

using namespace std;

// 声明
//inline void func666();
//inline int sum888(int v1, int v2);

/**
 使用内联函数：
 1、函数代码体积不大
 2、频繁调用的函数
 */

// 开启栈空间
inline void func666() {
    cout << "func1()" << endl;
    cout << "func2()" << endl;
    cout << "func3()" << endl;
}
// 回收栈空间

inline int sum888(int v1, int v2) {
    return v1 + v2;
}

// 宏
//#define add(v1, v2) v1 + v2

#define sumMaro(v) v + v

int sumFunc(int v) {
    return v + v;
}


int main() {

//    int c = add(10, 20);
//    cout << c << endl;
    
    int a = 10;
    int maroNum = sumMaro(++a);
    cout << maroNum << endl;

    int b = 10;
    int funcNum = sumFunc(++b);
    cout << funcNum << endl;
    
    
    // 表达式
    int aa = 10;
    int bb = 20;
    (aa = bb) = 30;
    (aa < bb ? aa : bb) = 100;
    // aa = 30  赋值给了aa
    cout << "aa = " << aa << endl;
    // bb = 20 赋值给了bb
    cout << "bb = " << bb << endl;
    
    
//    // 代价，开辟内存和回收内存
//    func666();

//    int c = sum888(10, 20);
//    cout << c << endl;
    
//    getchar();
    return 0;
}
