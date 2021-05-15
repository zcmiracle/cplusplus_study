//
//  main.cpp
//  52-Lambda表达式
//
//  Created by XFB on 2021/5/15.
//

#include <iostream>

/**
 
 Lambada 表达式 --- 本质就是函数，左侧用指向函数的指针就ok
 
 有点类似于 JavaScript中的闭包，iOS中的Block，本质就是函数
 完整结构：
 [capture list](params list) mutable exception -> return type { function body }
 
 capture list：捕获外部变量列表
 params list：形参列表，不能使用默认参数，不能省略参数名
 mutable：用来说明是否可以修改捕获的变量
 exception：异常设定
 return type：返回值类型
 function body：函数体
 
 有时候可以省略部分结构
 [catpure list](params list) -> return type { function body }
 [catpure list](params list) { function body }
 [catpure list]{ function body }

 */

int (*p1)(int, int) = [](int v1, int v2) -> int {
    return v1 + v2;
};

auto p2 = [](int v1, int v2) {
    return v1 + v2;
};

auto p3 = [](int v1, int v2) { return v1 - v2;}(20, 10);


auto p4 = [] {
    std::cout << "test" << std::endl;
};

// int (*func)(int, int) 传函数  指向函数的指针
int exec(int a, int b, int (*func)(int, int)) {
    if (func == nullptr) return 0;
    return func(a, b);
}

//int add(int v1, int v2) {
//    return v1 + v2;
//}
//
//int sub(int v1, int v2) {
//    return v1 - v2;
//}
//
//int multiple(int v1, int v2) {
//    return v1 * v2;
//}
//
//int divide(int v1, int v2) {
//    return v1 / v2;
//}


int main() {

    std::cout << p1(10, 20) << std::endl;
    std::cout << p2(10, 20) << std::endl;
    std::cout << p3 << std::endl;
    
    p4();
    
//    std::cout << exec( 20, 10, add(10, 20) ) << std::endl;
//    std::cout << exec( 20, 10, sub(10, 20) ) << std::endl;
//    std::cout << exec( 20, 10, multiple(10, 20) ) << std::endl;
//    std::cout << exec( 20, 10, divide(10, 20) ) << std::endl;

    std::cout << exec( 20, 10, [](int v1, int v2) { return v1 + v2; } ) << std::endl;
    std::cout << exec( 20, 10, [](int v1, int v2) { return v1 - v2; } ) << std::endl;
    std::cout << exec( 20, 10, [](int v1, int v2) { return v1 * v2; } ) << std::endl;
    std::cout << exec( 20, 10, [](int v1, int v2) { return v1 / v2; } ) << std::endl;

    
    getchar();
    return 0;
}
