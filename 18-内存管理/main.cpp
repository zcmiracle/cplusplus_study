//
//  main.cpp
//  18-内存管理
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>

// 全部都在栈上
struct Car1 {
    int m_price;
};

struct Person1 {
    int m_age;
    Car1 m_car;
};

//
struct Car2 {
    int m_price;
};

struct Person2 {
    int m_age;
    Car2 *m_car;
    
    Person2() {
        // new Car2 堆空间产生了Car2对象
        m_car = new Car2;
    }
    
    ~Person2() {
        delete m_car;
    }
};


struct Car {
    int m_price;
    
    // 构造函数
    Car() {
        m_price = 0;
        std::cout << "Car::Car()" << std::endl;
    }
    
    // 析构函数
    ~Car() {
        std::cout << "Car::~Car()" << std::endl;
    }
};

struct Person {
    int m_age;
    Car *m_car;
    
public:
    // 构造函数：用来做初始化的工作
    Person() {
        m_age = 0;
        m_car = new Car(); // 因为Car是new出来的，在堆空间，需要用户手动delete，不可能自动回收
        
        std::cout << "Person::Person()" << std::endl;
    }
        
    // 析构函数：用来做内存清理的工作
    // 清理内部产生的堆空间，不能
    ~Person() {
        // 在person挂的时候让car也销毁，如果写在下面，创建多个person就要销毁多次car
        delete m_car;
        
        std::cout << "Person::~Person()" << std::endl;
    }
};


int main() {
    
    {
//        Person person;
        
        // 加上这句话才会销毁Car，因为Car是new出来的，在堆空间，系统不会自动回收
//        delete person.m_car;
        /**
         结果显示 Car的析构函数没有调用
         Car::Car()
         Person::Person()
         Person::~Person()
         */
    
        // 全部都在栈空间
//        Person1 person1;
        
        // 指针变量p在栈空间上，其他的在堆空间
//        Person1 *p = new Person1();
        
        
        // 指针变量p2在栈空间，栈空间指针变量p2指向堆空间的person2对象，
        // person对象内部有两个成员变量一个 m_age 和 m_car
        // m_car 指向堆空间Car2对象，Car2对象里面有成员变量m_price
        Person2 *p2 = new Person2();
        
    }
    
    

    return 0;
}
