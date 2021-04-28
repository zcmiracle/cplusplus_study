//
//  math.h
//  03-extern_C
//
//  Created by XFB on 2021/4/28.
//

/// 防止重复#include "main.h" 重复参与编译
/// 宏定位最好和文件名挂钩 __ 下划线开头 也行
#ifndef math_h
#define math_h

//#include <stdio.h>

// 如果使用extern "C" 包装的话，意味着C++可以调用C语言的函数，但是C语言无法识别，会报错
// 所以使用 __cplusplus 宏判断是否是C++环境，才会参与编译
//extern "C" {
//    // header file：存放函数的声明
//    int sum(int v1, int v2);
//    int delta(int v1, int v2);
//    int divide(int v1, int v2);
//}


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    int sum(int v1, int v2);
    int delta(int v1, int v2);
    int divide(int v1, int v2);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* math_h */

