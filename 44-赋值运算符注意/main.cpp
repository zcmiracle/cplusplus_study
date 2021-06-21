//
//  main.cpp
//  44-赋值运算符注意
//
//  Created by XFB on 2021/5/13.
//

#include <iostream>
using namespace std;

class Person {
public:
    int m_age;
        
    Person &operator=(const Person &person) {
        m_age = person.m_age;
    } // Non-void function does not return a value
};

class Student: public Person {
public:
    int m_score;
    Student &operator=(const Student &student) {
        // 父类的m_age不能调用，调用父类的重载函数给m_age赋值
        // 类似于拷贝构造函数
        Person::operator=(student);
        m_score = student.m_score;
    } // Non-void function does not return a value
};

int main() {

    Student stu1;
    stu1.m_age = 20;
    stu1.m_score = 100;
    
    Student stu2;
    stu2 = stu1;
    
    getchar();
    return 0;
}
