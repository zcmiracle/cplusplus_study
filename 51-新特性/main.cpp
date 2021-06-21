//
//  main.cpp
//  51-新特性
//
//  Created by XFB on 2021/5/15.
//

#include <iostream>

/**
 新特性
 auto：
 可以从初始化表达式中推断出 变量的类型，大大简化编程工作
 属于编译器特性，不影响最终的机器码质量，不影响运行效率
 
 
 decltype：
 可以获取变量的类型
 
 nullptr
 可以解决NULL的二义性
 之前的空指针用NULL表示，现在用nullptr
 c++11 开始 NULL相当于整数0
 
 
 */

void func(int value) {
    std::cout << "func(int) - " << value << std::endl;
}

void func(int *value) {
    std::cout << "func(int *) - " << value << std::endl;
}

void test() {
//    func(0);
//    func(NULL);
//    func(nullptr);
    
    // 可以解决NULL的二义性
//    std::cout << (NULL == nullptr) << std::endl; // 1
}


int main() {

//    test();
    
    int a = 10;
    // decltype 获取变量的类型
    decltype(a) b = 20;
    
    // 快速遍历
    int array[] = {1, 2, 3, 4, 5};
    // for-in in=: in等于:
    for (int item : array) {
        std::cout << item << std::endl;
    }

    
    getchar();
    return 0;
}
