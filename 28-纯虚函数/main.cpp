//
//  main.cpp
//  28-纯虚函数
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>

/**
 纯虚函数：没有函数体 且 初始化为0 的虚函数，用来定义接口规范
 
 抽象类：Abstract class
 1、含有纯虚函数的类，不可以实例化（不可以创建对象）
 2、抽象类也可以包含 非纯虚函数、成员变量
 3、如果父类是抽象类，子类没有完全实现纯虚函数，那么这个子类依然是抽象类
 
 */


struct Animal {
    // 动物是可以speak和run，但是具体怎么run怎么speak交给子类去实现
    virtual void speak() = 0;
    virtual void run() = 0;
};

//struct Dog : Animal {
//    void speak() {
//        std::cout << "Dog::speak()" << std::endl;
//    }
//    void run() {
//        std::cout << "Dog::run()" << std::endl;
//    }
//};

struct Cat : Animal {
//    void speak() {
//        std::cout << "Cat::speak()" << std::endl;
//    }
    void run() {
        std::cout << "Cat::run()" << std::endl;
    }
};

struct WhiteCat : Cat {
    void speak() {
        std::cout << "WhiteCat::speak()" << std::endl;
    }
    void run() {
        std::cout << "WhiteCat::run()" << std::endl;
    }
};

struct GoodCat : Cat {
    void speak() {
        std::cout << "GoodCat::speak()" << std::endl;
    }
//    void run() {
//        std::cout << "GoodCat::run()" << std::endl;
//    }
};


int main() {

    // Variable type 'Animal' is an abstract class
    // 抽象类不可以创建对象
//    Animal animal;
    // 父类是抽象类，子类没有完全实现纯虚函数，那么这个子类依然是抽象类
//    Cat cat;
    
    // 子类完全实现了纯虚函数 speak() 和 run()
    WhiteCat whiteCat;
    // 不是抽象类，虽然只实现了speak()，但是他的父类实现了run()，子类完全实现纯虚函数
    GoodCat goodCat;
    
    
    getchar();
    return 0;
}
