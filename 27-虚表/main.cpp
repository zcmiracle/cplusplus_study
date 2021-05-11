//
//  main.cpp
//  27-虚表
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>


/**
 虚函数两种情况
 1、自己加了virtual
 2、父类是虚函数，子类重写了它
 
 
 虚析构函数
 存在父类指针指向子类对象，析构函数 声明为 虚函数(虚析构函数)
 如果有多态（如果存在父类指针指向子类对象），应该将析构函数声明为虚函数（虚析构函数）
 delete父类指针时，才会调用子类的析构函数，保存析构的完整性
 */

//struct Animal {
//    virtual void speak() {
//        std::cout << "Animal::speak()" << std::endl;
//    }
//    virtual void run() {
//        std::cout << "Animal::run()" << std::endl;
//    }
//};
//
//struct Cat : Animal {
//    void speak() {
//        std::cout << "Cat::speak()" << std::endl;
//    }
//    void run() {
//        std::cout << "Cat::run()" << std::endl;
//    }
//};
//
//struct WhiteCat : Cat {
//    void speak() {
//        std::cout << "WhiteCat::speak()" << std::endl;
//    }
//    void run() {
//        std::cout << "WhiteCat::run()" << std::endl;
//    }
//};

//// 父类没有虚表，直接看Animal * 指针类型
//struct Animal {
//    void speak() {
//        std::cout << "Animal::speak()" << std::endl;
//    }
//    void run() {
//        std::cout << "Animal::run()" << std::endl;
//    }
//};
//
//struct Cat : Animal {
//    virtual void speak() {
//        std::cout << "Cat::speak()" << std::endl;
//    }
//    virtual void run() {
//        std::cout << "Cat::run()" << std::endl;
//    }
//};
//
//struct WhiteCat : Cat {
//    void speak() {
//        std::cout << "WhiteCat::speak()" << std::endl;
//    }
//    void run() {
//        std::cout << "WhiteCat::run()" << std::endl;
//    }
//};



struct Animal {
    void speak() {
        std::cout << "Animal::speak()" << std::endl;
    }
    void run() {
        std::cout << "Animal::run()" << std::endl;
    }
    Animal() { // 构造函数
        std::cout << "Animal::Animal()" << std::endl;
    }
    virtual ~Animal() { // 析构函数
        std::cout << "Animal::~Animal()" << std::endl;
    }
};

struct Cat : Animal {
    virtual void speak() {
        std::cout << "Cat::speak()" << std::endl;
    }
    virtual void run() {
        std::cout << "Cat::run()" << std::endl;
    }
    Cat() { // 构造函数
        std::cout << "Cat::Cat()" << std::endl;
    }
    // 由于父类的析构函数声明为了虚函数virtual，子类也会是virtual虚析构函数
    ~Cat() { // 析构函数
        std::cout << "Cat::~Cat()" << std::endl;
    }
};


int main() {
    
//    Animal *cat = new Cat();
//    cat->speak();
//    cat->run();
//
//    Animal *whiteCat = new WhiteCat();
//    whiteCat->speak();
//    whiteCat->run();
//
//    Cat *whiteCat1 = new WhiteCat();
//    whiteCat1->speak();
//    whiteCat1->run();
    
    Animal *cat0 = new Cat();
    cat0->speak();
    delete cat0;
    
    
    getchar();
    return 0;
}
