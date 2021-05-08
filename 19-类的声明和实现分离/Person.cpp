//
//  Person.cpp
//  19-类的声明和实现分离
//
//  Created by XFB on 2021/5/8.
//

#include "Person.hpp"

// void setAge(int age); 的函数实现，加上类名 Person::
// 函数属于Person这个类,Person::只能放在函数名的前面
void Person::setAge(int age) {
    m_age = age;
}

// getter方法
int Person::getAge() {
    return m_age;
}

// 构造方法
Person::Person() {
    m_age = 0;
}

// 析构函数
Person::~Person() {
    
}
