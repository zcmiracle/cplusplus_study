//
//  main.cpp
//  41-内部类
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>

/**
 内部类：
 如果将类A 定义在类C的内部，那么类A就是一个内部类（嵌套类）
 
 内部类的特点：
 1、支持public、protected、privated权限
 2、成员函数可以直接访问外部类对象的所有成员，不管是private还是public等（反过来则不行）
 3、成员函数可以直接不带类名、对象名访问器外部类的static成员
 4、内部类不影响外部类的内存布局
 5、可以在外部类内部声明，在外部类外面进行定义
 
 */


//class Point {
//    class Math {
//        // 外部类内部声明，外部类外面进行定义实现
//        void test1();
//    };
//};
//
//// 实现
//void Point::Math::test1() {
//
//}


//class Point {
//    class Math;
//};
//
//class Point::Math {
//    void test1() {
//
//    }
//};



class Point {
    class Math;
};

class Point::Math {
    void test1();
};

// 实现
void Point::Math::test1() {
    
};


// 某个类只存在另外一个类里面，外界使用不到，使用内部类
class Person {
private:
    int m_age;
    // 静态成员及静态函数
    static int m_height;
    static void test() {}
    
    // 反过来则不行
//    void test() {
//        Car car;
//        car.m_price = 10;
//    }
        
public:
    // 内部类
    class Car {
    private:
        int m_price;
        
        // 内部类成员函数能访问外部类对象的所有成员(反过来则不行)
        void run() {
            Person person;
            person.m_age = 10;
            // 静态成员可以通过类名访问
            Person::m_height = 180;
            Person::test();
            // 静态成员也可以通过对象名访问
            person.m_height = 170;
            person.test();
            
            // 静态成员也可以直接访问
            m_height = 175;
            test();
        }
    };
};

    
int main() {
    
    Person::Car car1;
    Person::Car car2;
    
    // 内部类不影响对象的内存布局
    Person person;


    getchar();
    return 0;
}
