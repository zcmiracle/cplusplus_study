//
//  main.cpp
//  14-构造函数
//
//  Created by XFB on 2021/5/7.
//

#include <iostream>


/**
 构造函数：（构造器）
 在对象创建的时候自动调用，一般用于完成对象的初始化工作
 特点：构造函数可以重载
 1、函数名与类名相同，无返回值 void都不能写，可以有参数，可以重载，可以有多尔衮构造函数
 2、一旦自定义了构造函数，必须用其中一个自动以的构造函数来初始化对象

 
 注意：
 
 
 */

struct Person {
    int m_age;
    int m_money;
    
    
    void run() {
        std::cout << "Person::run - " << m_age << std::endl;
    }
    
    // 构造函数，和类名一样，会自动调用构造函数
    // 无参的构造函数
    Person() {
        std::cout << "Person()" << std::endl;
    }
    
    Person(int age) {
        m_age = age;
        std::cout << "Person(int age)" << std::endl;
    }
    
    Person(int age, int money) {
        m_age = age;
        m_money = money;
        std::cout << "Person(int age, int money)" << std::endl;
    }
    
    void display() {
        std::cout << "age is " << m_age << ", money is " << m_money << std::endl;
    }
};


// 全局区的person
Person g_person;

int main() {

    // 栈空间
    Person person1;
    Person person2(20);
    Person person3(30, 300);
    
    // 堆空间 new除了申请堆空间内存，比malloc多做了 调用了构造函数
    // 所以申请堆空间，一般用new，不用malloc，malloc只是申请堆空间，没有初始化
    Person *p = new Person();
    // 堆空间要手动删除 delete 和 new是一起的
    delete p;
    
    person1.display();
    person2.display();
    person3.display();
    
    // 通过malloc创建的对象是不会调用构造函数
    // sizeof是编译器特性，
    Person *p1 = (Person *)malloc(sizeof(Person));
    p1->m_age = 10;
    p1->run();
    
    free(p1);
     
    return 0;
}


/**
重点：默认情况下，编译器会为每一个类生成空的无参的构造函数。
这句话错误：
 正确理解：在某些特定的情况下，编译器才会为类生成空的无参的构造函数
 1、虚函数
 2、...
 
 */
