//
//  main.cpp
//  50-类型转换
//
//  Created by XFB on 2021/5/15.
//

#include <iostream>
using namespace std;


/**
 类型转换
 (type)expression
 type(expression)
 
 c++中有4个类型转换符
 static_cast
 dynamic_cast
 reinterpret_cast
 const_cast
 
 格式：xxx_cast<type>(expression)
 
 
 const_cast
 一般用于去除const属性，将const 转换成非const

 
 dynamic_cast
 一般用于多态类型的转换，有运行时安全监测
 
 
 static_cast
 对比dynamic_cast，缺乏运行时安全检测
 不能交叉转换（不是同一继承提心，无法转换）
 常用语基本数据类型的转换，【非const转成const】
 使用范围较广
 
 
 reinterpert_cast
 比较底层的强制转换，没有任何类型检查和格式转换，仅仅是简单的二进制数据拷贝
 可以交叉转换
 可以将指针和整数互相转换
 
 */


class Person {
public:
    int m_age;
    virtual void run() {}
};

class Student: public Person {
    
};

class Car {
    
};

int main() {
    
    // const_cast
    const Person *p1 = new Person();
//    p1->m_age = 10;
    // 去除const，能修改值
    Person *p2 = const_cast<Person *>(p1);
    p2->m_age = 20;
    
    
    // dynamic_cast
    Person *person1 = new Person();
    Person *person2 = new Student();
    
    Student *student1 = dynamic_cast<Student *>(person1); // 不安全
    Student *student2 = dynamic_cast<Student *>(person2); // 安全
    Car *car1 = dynamic_cast<Car *>(person1);
    
    std::cout << "student1 = " << student1 << std::endl; // 不安全
    std::cout << "student2 = " << student2 << std::endl; // 安全
    std::cout << "car1 = " << car1 << std::endl; // car = 0x0
        
    
    
    // static_cast
    Person *person3 = new Person();
    Person *person4 = new Student();
    
    Student *student3 = static_cast<Student *>(person3);
    Student *student4 = static_cast<Student *>(person4);
    // 不能交叉转换，因为Car 和 person和student无关
//    Car *car2 = static_cast<Car *>(person3);

    std::cout << "student3 = " << student3 << std::endl;
    std::cout << "student4 = " << student4 << std::endl;
//    std::cout << "car2 = " << car2 << std::endl;
    
    
    
    // reinterpret_cast
    Person *person5 = new Person();
    Person *person6 = new Student();
    
    Student *student5 = reinterpret_cast<Student *>(person5);
    Student *student6 = reinterpret_cast<Student *>(person6);
    Car *car3 = reinterpret_cast<Car *>(person5);
    
    std::cout << "student5 = " << student5 << std::endl;
    std::cout << "student6 = " << student6 << std::endl;
    std::cout << "car3 = " << car3 << std::endl;
    
    
    int *p = reinterpret_cast<int *>(0x100);
    // 不同数据类型转换要写引用 & 这里的int &就是这样
    // int * 转成int
    int a = reinterpret_cast<int &>(p);
    cout << "a = " << a << endl;

    int num = reinterpret_cast<int &>(p);
    int i = 100;
    // 不同数据类型转换要写引用 & 这里的double &就是这样
    // int 转 double要添加引用
    double double1 = reinterpret_cast<double &>(i);
    
    cout << "num = " << num << endl;
    cout << "double1 = " << double1 << endl;

    
    
    
    getchar();
    return 0;
}
