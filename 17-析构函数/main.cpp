//
//  main.cpp
//  17-析构函数
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>

/**
 析构函数：Destructor
 析构函数：析构器，在对象销毁的时候自动调用，一般用于完成对象的清理工作
 
 特点：
 函数名以 ~ 开头，与类同名，无返回值，void都不能写，无参，不可以重载，有且只有一个析构函数
 
 注意：
 通过malloc分配的对象free的时候不会调用析构函数
 因为通过malloc分类的对象不会调用构造函数

 构造函数、析构函数要声明为 public，才能被外界正常使用
 
 */


struct Person {
    
    int m_age;
    
public:
    // 构造函数和析构函数 都要public才能被外界使用
    // 用来做初始化的工作
    Person() {
        std::cout << "Person::Person()" << std::endl;
    }
        
    // 一个Person对象销毁的象征
    // 用来做内存清理的工作
    ~Person() {
        std::cout << "Person::~Person()" << std::endl;
    }
};


void test() {
    Person person;
}

// 全局区的person是看不到析构，程序运行中，一直在内存中间
Person g_person;

int main() {

//    std::cout << 1 << std::endl;
//    test();
//    std::cout << 2 << std::endl;
    
    // 堆空间
    Person *p = new Person;
    delete p;
    
    
    getchar();
    return 0;
}
