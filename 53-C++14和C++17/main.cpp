//
//  main.cpp
//  53-C++14和C++17
//
//  Created by XFB on 2021/5/15.
//

#include <iostream>

/**
 C++14
 泛型Lambda表达式
 对捕获的变量进行初始化
 
 C++17
 可以进行初始化if、switch语句
 
 */

int main() {

    // 泛型Lambda表达式
    auto func1 = [](auto v1, auto v2) {
        return v1 + v2;
    };
    std::cout << func1(10, 10.5) << std::cout;
    
    
    // 对捕获的变量进行初始化
    int a;
    auto func2 = [a = 10]() {
        std::cout << a << std::endl;
    };
    func2();
    // 这里任然是未初始化
    std::cout << a << std::endl;
    
    if (int aa = 10, a > 10) {
        aa = 1;
    } else if (int bb = 20, aa > 5 && bb > 10) {
        bb = 2;
        aa = 2;
    } else if (0) {
        bb = 3;
        aa = 3;
    } else {
        bb = 4;
        aa = 4;
    }
    
    // 都是编译器特性，汇编变化不大，语法糖而已
    switch (int a = 10; a) {
        case 1:
            break;
        case 5:
            break;
        case 10:
            break;
        default:
            break;
    }
        
    return 0;
}
