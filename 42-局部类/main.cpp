//
//  main.cpp
//  42-局部类
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>

/**
 局部类：
 函数内部定义的类是局部类
 
 特点：
 1、作用域仅限于所在的【函数内部】
 2、其所有的成员必须定义在类内部、不允许定义static成员变量
 3、成员函数不能直接访问函数的局部变量（static变量除外）
 */

void test() {
    // 函数的局部变量只有在函数调用的时候才存在吗，才会分配存储空间
    // 所以在类中不能直接访问函数的局部变量
    int m_height = 10;
    
    static int age = 10;
    class Car {
        // 其所有的成员必须定义在类内部
        int m_price;
        
        // 不允许定义static成员变量
//        static int m_price;
    public:
        void run() {
            // 所以在类中不能直接访问函数的局部变量
//            m_height = 100;
            age = 20;
        }
    };
    
    // 这两句执行，上面是类的定义，每次函数调用都执行这两句，上面不会执行
    Car car;
    car.run();
}

int main() {
    
    
    getchar();
    return 0;
}
