//
//  main.cpp
//  16-成员变量的初始化
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>


/**
 如果自定义构造函数，除了全局区，其他内存空间的成员变量默认都不会被初始化，需要开发者手动初始化
 */

struct Person {
    // 默认情况下，成语变量的初始化
    int m_age;
    
    // 自己写构造函数，但是不去实现
//    Person() {
//
//    }
};

// 全局区：成员变量初始化为0
Person g_person;


int main() {

    // 栈空间：没有初始化成员变量
//    Person person;
    
    // 堆空间：没有初始化成员变量
    Person *p1 = new Person;
    // 堆空间：成员变量初始化为0
    Person *p2 = new Person();
    
    // 成员变量不会被初始化？？？
    Person *p3 = new Person[3]; // 成员变量不会被初始化？？？
    Person *p4 = new Person[3](); // 3个person对象的成员变量都初始化为0
    Person *p5 = new Person[3]{};  // 3个person对象的成员变量都初始化为0

    
    std::cout << g_person.m_age << std::endl; // 0
//    std::cout << person.m_age << std::endl; // 86053
    std::cout << p1->m_age << std::endl; // 0
    std::cout << p2->m_age << std::endl; // 0
    
    std::cout << p3->m_age << std::endl; // 0
    std::cout << p4->m_age << std::endl; // 0
    std::cout << p5->m_age << std::endl; // 0
    
    getchar();
    return 0;
}
