//
//  main.cpp
//  34-const
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>

/**
 常引用 Const Reference
 引用可以被 const 修饰，这样就无法通过引用修改数据了，可以称为常引用
 cosnt 必须写在 & 符号的左边，才能算是常引用
 
 const 引用的特点
 可以指向临时数据（常量、表达式、函数返回值等）
 可以指向不同类型的数据
 
 作为函数参数时（此规则也适用于 const 指针）
    可以接受const 和 非const 实参（非const引用，只能接受非const实参）
    可以跟非const引用构成重载
 
 当常引用指向了不同类型的数据时，会产生临时变量，即引用指向的并不是初始化时的那个变量
 
 */


class Car {
public:
    int m_price;
    void run() const {
        std::cout << "run() const" << std::endl;
    }
};


int main() {

    Car car;
    car.run();
    
//    const Car car2;
//    car2.run();
    
    getchar();
    return 0;
}
