//
//  swap.hpp
//  47-函数模板
//
//  Created by XFB on 2021/5/14.
//

#ifndef swap_hpp
#define swap_hpp

#include <stdio.h>

// 声明
template <class T> void swapValues(T &v1,T &v2);

// 实现
template <class T>
void swapValues(T &v1, T &v2) {
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

#endif /* swap_hpp */
