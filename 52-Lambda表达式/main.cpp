//
//  main.cpp
//  52-Lambda表达式
//
//  Created by XFB on 2021/5/15.
//

#include <iostream>
using namespace std;

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

    
    int a = 1000;
    int b = 2000;
    // 默认都是值捕获
    auto func1 = [a] {
        cout << "值捕获 a = "<< a << endl;
    };
    
    // 地址捕获 访问最新的a 相当于引用传递 引用了外面的a
    auto func2 = [&a, b] { // a是地址(引用)捕获，b是值捕获
        cout << "地址捕获 a = " << a << endl;
        cout << "值捕获 b = " << b << endl;
    };
    
    // 隐式捕获
    auto func3 = [=] {
        cout << "隐式捕获 a = " << a << endl;
        cout << "隐式捕获 b = " << b << endl;
    };
    
    // a是值捕获，其余变量是地址捕获
    auto func4 = [&, a] {
        cout << "a是值捕获 a = " << a << endl;
        cout << "其他是地址捕获 = " << b << endl;
    };
    
    
//    int a = 1000;
//    int b = 2000;
//    // 默认都是值捕获
//    auto func1 = [a] {
//        std::cout << "值捕获 a = "<< a << std::endl;
//    };
//
//    // 地址捕获 访问最新的a 相当于引用传递 引用了外面的a
//    auto func2 = [&a, b] { // a是地址(引用)捕获，b是值捕获
//        std::cout << "地址捕获 a = " << a << std::endl;
//        std::cout << "值捕获 b = " << b << std::endl;
//    };
//
//    // 隐式捕获
//    auto func3 = [=] {
//        std::cout << "隐式捕获 a = " << a << std::endl;
//        std::cout << "隐式捕获 b = " << b << std::endl;
//    };
//
//    // a是值捕获，其余变量是地址捕获
//    auto func4 = [&, a] {
//        std::cout << "a是值捕获 a = " << a << std::endl;
//        std::cout << "其他是地址捕获 = " << b << std::endl;
//    };
    
 
    
    a = 200;
    b = 100;
    
    func1(); // 值捕获
    func2(); // 地址捕获
    func3(); // 隐式捕获
    func4(); // &, a ---> a是值捕获，其余变量是地址捕获

    
    
    auto func5 = [a] () mutable {
        a++;
        std::cout << "lambda 中的a = " << a << std::endl;
    };
    
    func5();
    std::cout << "lambda 外的a = " << a << std::endl;

    
    
    getchar();
    return 0;
}
