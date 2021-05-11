//
//  main.cpp
//  30-菱形继承
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>

/**
 菱形继承：
 菱形继承带来的问题
 1、最底下子类从基类继承的成员变量冗余、重复
 2、最底下子类无法访问基类的成员、有二义性

 虚继承
 虚继承可以解决菱形继承带来的问题

 
 虚表指针 与 本类起始的偏移量（一般是0）
 虚基类第一个成员变量 与 本类起始的偏移量
 
 
 */

// 虚继承
struct Person {
    // 4个字节指针
    int m_age = 0; // 4
};

struct Student: virtual Person {
    int m_score = 2;
};

struct Worker: virtual Person {
    int m_salary = 3;
};

struct Undergraduate: Student, Worker {
    int m_grade = 4;
};

int main() {

    Undergraduate ug;
    ug.m_age = 5;
    std::cout << sizeof(Undergraduate) << std::endl;
    
    std::cout << sizeof(Person) << std::endl;
    std::cout << sizeof(Student) << std::endl;
    std::cout << sizeof(Worker) << std::endl;

    getchar();
    return 0;
}
