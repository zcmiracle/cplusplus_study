//
//  main.cpp
//  03-extern_C
//
//  Created by XFB on 2021/4/28.
//

#include <iostream>
#include "math.h"

using namespace std;

// c++ 在最前面默认有这个宏
//#define __cplusplus

/**
 报错：
 Showing All Messages
 Undefined symbol: sum(int, int)
 Undefined symbol: delta(int, int)
 */
// 这样声明 直接会报错
//int sum(int v1, int v2);
//int delta(int v1, int v2);

// C++ 调用C语言函数的时候


extern "C" void test();

int main() {

//    func();
//    func(10);
    
    cout << sum(10, 20) << endl;
    cout << delta(30, 20) << endl;
    cout << divide(30, 10) << endl;

    // C语言调用
    test();
    
    getchar();
    
    return 0;
}


#if 0

//extern "C" void func() {
//
//}
//
//// func 不允许重载函数
//extern "C" void func(int value) {
//
//}


//extern "C" {
//
//    void func() {
//
//    }
//
//    void func(int value) {
//
//    }
//}

// 可以放在声明中，不要放在实现中 extern "C"
//extern "C" void func();
//extern "C" void func(int v);


void func() {
    cout << "func()" << endl;
}

void func(int value) {
    cout << "func(int v)" << endl;
}
#endif
