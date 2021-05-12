//
//  main.cpp
//  35-拷贝构造
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>

class Car {
public:
    int m_price;
    int m_length;
    // 构造函数
    Car(int price = 0, int length = 0) :m_price(price), m_length(length) {
        std::cout << "Car(int price = 0, int length = 0)" << std::endl;
    }
    // 拷贝构造函数
    Car(const Car &car) :m_price(car.m_price) {
        std::cout << "Car(const Car &car)" << std::endl;
    }
    
    void display() {
        std::cout << "price = " << m_price << ", length = " << m_length << std::endl;
    }
};

class Car1 {
public:
    int m_price;
    int m_length;
    // 构造函数
    Car1(int price = 0, int length = 0) :m_price(price), m_length(length) {
        std::cout << "Car1(int price = 0, int length = 0)" << std::endl;
    }
    // 拷贝构造函数
    Car1(const Car1 &car) :m_price(car.m_price), m_length(car.m_length) {
        std::cout << "Car1(const Car1 &car)" << std::endl;
    }
    
    void display() {
        std::cout << "price = " << m_price << ", length = " << m_length << std::endl;
    }
};


class Person {
public:
    int m_age;
    Person(int age = 0) :m_age(age) {}
    Person(const Person &person) : m_age(person.m_age) {}
};

class Student : public Person {
public:
    int m_score;
    Student(int age = 0, int score = 0) : Person(age), m_score(score) {}
//    Student(const Student &student) : m_score(student.m_score) {}
    // 可以不写，系统默认会赋值
//    Student(const Student &student)  : Person(student.m_age), m_score(student.m_score) {}
};


int main() {
    
    Car car1(100, 5);   // Car(int price = 0, int length = 0)
    Car car2(car1);     // Car(const Car &car)
    Car car3 = car2;    // Car(const Car &car)
    Car car4;           // Car(int price = 0, int length = 0)

    car4.display();     // price = 0, length = 0
    car4 = car3;        // 没调用拷贝构造函数 仅仅是简单的赋值操作
    car4.display();     // price = 100, length = 0

    // 利用一个已经存在的car5对象创建了一个car6新对象
    Car1 car5(100, 5);  // Car1(int price = 0, int length = 0)
    Car1 car6(car5);    // Car1(const Car &car)
//    car6.m_price = car5.m_price;
//    car6.m_length = car5.m_length;

    
    
    Car1 car7 = car6;   // Car1(const Car &car)
    Car1 car8;          // Car1(int price = 0, int length = 0)
    car8.display();     // price = 0, length = 0
    car6.display();     // price = 100, length = 5

    
    Student stu1(20, 2000);
    Student stu2(stu1);
    
    std::cout << stu2.m_age << std::endl;  // 0
    std::cout << stu2.m_score << std::endl; // 2000

    
    getchar();
    return 0;
}
