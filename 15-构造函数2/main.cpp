//
//  main.cpp
//  15-构造函数2
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>


struct Person {
    int m_age;
    
    Person() {
        std::cout << "Person()" << std::endl;
    }
    
    Person(int age) {
        m_age = age;
        std::cout << "Person(int age)" << std::endl;
    }
};

// 全局区
Person g_person1; // Person()
Person g_person2(); // 函数声明，不会调用构造函数
Person g_person3(20); // Person(int age)

int main() {

    // 栈空间
    Person person1; // Person()
    Person person2(); // 函数声明，不会调用构造函数
    Person person3(20); // Person(int age)
    
    // 堆空间
    Person *p1 = new Person; // Person()
    Person *p2 = new Person(); // Person()
    Person *p3 = new Person(20); // Person(int age)
    
    
    getchar();
    return 0;
}
