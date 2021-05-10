//
//  main.cpp
//  25-父类的构造函数
//
//  Created by XFB on 2021/5/10.
//

#include <iostream>

/**
 父类的构造函数
 1、子类的构造函数 默认 会调用父类的无参构造函数
 2、如果子类的构造函数显式地 调用了 父类的有参构造函数，就不会再去默认调用父类的无参构造函数
 3、如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数
 
 */

class Person1 {
    int m_age;

public:
    Person1(int age) :m_age(age) {}
};

class Student1: Person1 {
    int m_no;
public:
    Student1(int age, int no) :m_no(no), Person1(age) { }
};



struct Person {
    Person() {
        std::cout << "Person::Person()" << std::endl;
    }
    
    ~Person() {
        std::cout << "Person::~Person()" << std::endl;
    }
};

struct Student : Person {
    Student() {
        // 在这句之前会调用父类的无参构造函数
        // call Person::Person() 构造函数
        std::cout << "Student::Student()" << std::endl;
    }
    
    ~Student() {
        std::cout << "Student::~Student()" << std::endl;
        // call Person::~Person() 析构函数
    }
};



int main() {
    
    Student1 stu1(10, 20);

    {
        Student student;
        /**
         打印结果：子类初始化前会调用父类无参构造函数，子类析构后调用父类的析构函数
         Person::Person()
         Student::Student()
         Student::~Student()
         Person::~Person()
         */
    }
    
    getchar();
    return 0;
}
