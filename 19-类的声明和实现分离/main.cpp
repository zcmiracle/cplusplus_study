//
//  main.cpp
//  19-类的声明和实现分离
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>
#include "Person.hpp"

//class Person {
//private:
//    int m_age;
//public:
//    // 旧版本
//    // setter方法
//    void setAge(int age) {
//        m_age = age;
//    }
//
//    // getter方法
//    int getAge() {
//        return m_age;
//    }
//
//    // 构造方法
//    Person() {
//        m_age = 0;
//    }
//
//    // 析构方法
//    ~Person() {
//
//    }
//
//    // 声明
//    void setAge(int age);
//    int getAge();
//    Person();
//    ~Person();
//};

//
//// void setAge(int age); 的函数实现，加上类名 Person::
//// 函数属于Person这个类,Person::只能放在函数名的前面
//void Person::setAge(int age) {
//    m_age = age;
//}
//
//// getter方法
//int Person::getAge() {
//    return m_age;
//}
//
//// 构造方法
//Person::Person() {
//    m_age = 0;
//}
//
//// 析构函数
//Person::~Person() {
//
//}


int main() {

    Person person;
    person.setAge(20);
    std::cout << person.getAge() << std::endl;
    
    getchar();
    return 0;
}
