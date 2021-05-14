//
//  main.cpp
//  47-函数模板
//
//  Created by XFB on 2021/5/14.
//

#include <iostream>
#include "swap.hpp"

int main() {
    
    int a = 10;
    int b = 20;
    
//    swapValues<int>(a, b);
    swapValues(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    getchar();
    return 0;
}
