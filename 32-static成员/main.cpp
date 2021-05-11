//
//  main.cpp
//  32-static成员
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>
using namespace std;

/**
 静态成员static
 静态成员：被 static 修饰的成员变量/函数
 可以通过 对象（对象.静态成员）、 对象指针（对象指针->静态成员）、 类访问（类名::静态成员）
 
 静态成员变量
    存储在数据段（全局区，类似于全局变量），整个程序运行过程中只有一份内存
    对比全局变量，它可以设定访问权限（public、protected、private），达到【局部共享的目的】
    必须初始化，并且必须在类外面初始化，初始化时不能带static。如果类的声明和实现分离（在实现.cpp中初始化）
 
 静态成员函数
    内部不能使用this指针（this指针只能用在非静态成员函数内部）
    不能是虚函数（虚函数只能是非静态成员函数，因为虚函数用在多态，要对象来调用）
    内部不能访问非静态成员变量/函数。只能访问静态成员变量/函数
    非静态成员函数内部可以访问静态成员变量、函数
    构造函数、析构函数不能是静态的
    当声明和是实现分离时，实现部分不能带static
 */

class Cat {
public:
    int m_age;
    static int m_price;
    static void run() {
        std::cout << "run()" << std::endl;
    }
    
    static void speak();
    void test() {
        // 访问静态成员函数
        speak();
        // 访问静态成员变量
        m_price = 100;
    }
};
// 在类的外面进行初始化
int Cat::m_price = 0;




class Person {
public:
    static int m_age;
};
// 在类外面对静态成员变量初始化
int Person::m_age = 0;



class Student : public Person {
public:
    static int m_age;
};
// 在类外面对静态成员变量初始化
int Student::m_age = 0;



class Car {
private:
    static int m_counts;
public:
    Car() { // 构造函数
        m_counts++;
    }
    ~Car() { // 析构函数
        m_counts--;
    }
    // 添加static是因为 如果m_counts通过类名访问，不是通过对象来访问就会失效
    // 所以添加static，将来可以通过类名 也可以通过对象来访问
    static int getCount() { // getter方法
        return m_counts;
    }
};
// 在类外面对静态成员变量初始化
int Car::m_counts = 0;


Car g_car;

int main() {
    Car car;

    Car *p = new Car();
    delete p;
    
    // 用类名去调用，所以在getCount 前加上了static
    cout << Car::getCount() << endl;

    getchar();
    return 0;
};
