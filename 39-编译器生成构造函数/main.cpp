//
//  main.cpp
//  39-编译器生成构造函数
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>

/**
 编译器会为每个类生成空的无参构造函数，不一定正确
 
 
 C++ 的编译器在某些特定的情况下，会给类自动生成无参的构造函数，比如：
 1、成员变量在声明的时候进行了初始化 比如int m_age = 0;
 2、有定义虚函数
 3、虚继承其他类
 4、包含了对象类型的成员，且这个成员有构造函数（编译器生成或自定义）
 5、父类有构造函数（编译器生成或自定义）
 
 总结：
 1、对象创建后，需要做一些额外的操作时（比如内存操作、函数调用）。编译器一般都会为其
 自动生成无参的构造函数
 
 
 */

class Person {
public:
    
    // 1、成员变量在声明的时候进行了初始化 比如int m_age = 0;
//    int m_age = 10; // 会生成构造函数，要初始化值
    int m_age; // 不会生成构造函数

    // 如果是virtual 虚函数会生成构造函数
    // 因为虚函数person最前面会多出4个字节
    // 这4个字节存储虚表地址
    // 这种情况会生成构造函数
    // 2、有定义虚函数
//    virtual void run() {}
    void run() {}
    
    // 5、父类如果有构造函数，子类会调用父类的构造函数，
//    Person() {} // Student::Student at main.cpp:48
    
};

// 虚继承
// 虚继承某个类，这个对象最前面4个字节是虚表地址
// 3、虚继承其他类
//class Student: virtual public Person {

//class Student: public Person {
//public:
//
//};

class Student {
public:
    int m_price;
    void run() { }
};


class Car {
public:
    int m_price = 1;
    
    /**
     Car() {} 不存在 && int m_price 没有初始化值，不会生成Person的构造函数
     Car() {} 不存在 && int m_price = 0 有初始化值，会生成Person的构造函数
     Car() {} 存在，int m_price; 没有初始化值，会生成Person的构造函数
     Car() {} 存在，int m_price; 有初始化值，会生成Person的构造函数
     
     反正两者满足其一就行，成员变量有初始化值，
     或者包含了对象类型的成员，且这个成员有构造函数（编译器生成或自定义）
     就会有构造函数
    
     int price = 1; 相当于如下

     Car() {
        m_price = 1
     }
     
     */
    // 构造函数
    Car() {}
};

class Person1 {
public:
    Car car;
};


int main() {

//    Person person;
//    Person1 person1; // 不会有构造函数

    // 此情况会默认初始化为0， m_age = 0
    // new Person() 会默认将m_age初始化为0
//    Person *person2 = new Person();
    
    Student student;
    // 构造函数：创建完对象的那一刻，要不要做额外的操作，马上要做一些事情
    // 没有生成构造函数 Student::Student
    student.run(); //  Student::run
    
    getchar();
    return 0;
}



#if 0

class Person {
public:
    int m_age;
};


m_age 是没有初始化的
39-编译器生成构造函数`main:
    0x100003f70 <+0>:  pushq  %rbp
    0x100003f71 <+1>:  movq   %rsp, %rbp
    0x100003f74 <+4>:  subq   $0x10, %rsp
    0x100003f78 <+8>:  movl   $0x0, -0x4(%rbp)
    0x100003f7f <+15>: callq  0x100003f92               ; symbol stub for: getchar
    0x100003f84 <+20>: xorl   %ecx, %ecx
    0x100003f86 <+22>: movl   %eax, -0xc(%rbp)
    0x100003f89 <+25>: movl   %ecx, %eax
    0x100003f8b <+27>: addq   $0x10, %rsp
    0x100003f8f <+31>: popq   %rbp
    0x100003f90 <+32>: retq




class Person {
public:
    int m_age = 10;
};

// 成员变量初始化 为10 后生成的汇编
m_age = 10;

39-编译器生成构造函数`main:
    0x100003f30 <+0>:  pushq  %rbp
    0x100003f31 <+1>:  movq   %rsp, %rbp
    0x100003f34 <+4>:  subq   $0x10, %rsp
    0x100003f38 <+8>:  movl   $0x0, -0x4(%rbp)
    0x100003f3f <+15>: leaq   -0x8(%rbp), %rdi
    // Person::Person
    0x100003f43 <+19>: callq  0x100003f60               ; Person::Person at main.cpp:20
    0x100003f48 <+24>: callq  0x100003f94               ; symbol stub for: getchar
    0x100003f4d <+29>: xorl   %ecx, %ecx
    0x100003f4f <+31>: movl   %eax, -0xc(%rbp)
    0x100003f52 <+34>: movl   %ecx, %eax
    0x100003f54 <+36>: addq   $0x10, %rsp
    0x100003f58 <+40>: popq   %rbp
    0x100003f59 <+41>: retq



#endif
