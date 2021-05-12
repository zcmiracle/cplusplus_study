//
//  main.cpp
//  36-深拷贝
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>
#include <stdio.h>

/**
 浅拷贝：指针类型变量只会拷贝地址 shallow copy
 深拷贝：将指针指向的内容拷贝到新的存储空间 deep copy
 */


class Car {
    int m_price;
    char *m_name;

    void copy(const char *name = NULL) {
        if (name == NULL) return;
        // 申请新的堆空间
        // strlen(name) + 1，加1是因为\0结尾
        // {} 是将里面空间初始化为0
        m_name = new char[strlen(name) + 1] {};
        // 拷贝字符串数据到新的堆空间
        strcpy(m_name, name);
    }
    
public:
    // 构造函数
    Car(int price, const char *name = NULL) :m_price(price) {
        copy(name);
    }
    // 拷贝构造函数
    Car(const Car &car) :m_price(car.m_price) {
        copy(car.m_name);
    }
    
    ~Car() {
        if (m_name == NULL) return;
        delete[] m_name;
        m_name = NULL;
    }
    
    void display() {
        std::cout << "price is = " << m_price << ", name is = " << m_name << std::endl;
    }
};

int main() {

//    Car *car = new Car(100, "WB");
//    car->display();
    
//    const char *name = "BMW";
//    char name[] = { 'B', 'M', 'W', '\0' };
    char *name = new char[4]{ 'B', 'M', 'W', '\0' };
    
//    Car car1(100, "TS");
    Car car1(100, name);
    Car car2 = car1;
    car2.display();
    
    delete [] name;
    
    
    getchar();
    return 0;
}
