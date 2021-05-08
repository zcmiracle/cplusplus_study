//
//  main.cpp
//  21-继承
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>

/**
 继承：可以让子类拥有父类的所有成员（变量or函数）
 关系描述：
    Student 子类 subClass，派生类
    Person 父类 superClass 超类
 
 C++ 中没有Java、Objective-C的基类
 基类：最基本的类，其他所有的类都最终会继承自它。
 */
//struct Person {
//    int m_age;
//    void run() {
//        std::cout << "Person::run()" << std::endl;
//    }
//};
//
//
//// Student 继承 Person
//struct Student : Person {
//    int m_score;
//
//    void study() {
//        std::cout << "Student::study()" << std::endl;
//    }
//};
//
//// Worker 继承 Person
//struct Worker : Person {
//    int m_salary;
//
//    void work() { }
//};


struct Person {
    int m_age;
};

struct Student : Person {
    int m_no;
};

struct GoodStudent : Student {
    int m_money;
};


int main() {

//    Student student;
//    student.m_age = 20;
//    student.run();
//    student.study();
  
    GoodStudent goodStudent;
    Student student;
    Person person;
    
    // 对象的内存布局 age 在最前面 no 在中间，money在最后
    // 总结：从父类继承的成员变量，排列在最前面
    goodStudent.m_age = 20;
    goodStudent.m_no = 1;
    goodStudent.m_money = 10000;
    
//    std::cout << sizeof(goodStudent) << std::endl; // 12
//    std::cout << sizeof(student) << std::endl; // 8
//    std::cout << sizeof(person) << std::endl; // 4

    std::cout << &goodStudent.m_age << std::endl; // 0x7ffeefbff500
    std::cout << &goodStudent.m_no << std::endl; // 0x7ffeefbff504
    std::cout << &goodStudent.m_money << std::endl; // 0x7ffeefbff508
    
    getchar();
    return 0;
}
