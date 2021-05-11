//
//  main.cpp
//  33-单例模式
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>

/**
 单例模式： 保证某个类永远只创建一个对象
 
 1、构造函数私有化、析构函数私有化
 2、定义一个私有的static成员变量并指向唯一的那个单例对象
 3、提供一个公共的访问单例对象的接口
 */

class Cat {
private:
    Cat() {} // 构造函数私有化
    ~Cat() {} // 析构函数私有化
    static Cat *m_cat; // 使用* 对象能放堆空间就放堆空间，更灵活手动管理
public:
    // 单例
    static Cat *sharedCat() {
        if (m_cat == NULL) {
            m_cat = new Cat();
        }
        return m_cat;
    }
    
    static void deleteCat() {
        if (m_cat != NULL) {
            delete m_cat;
            // 指针清空，不然会产生野指针
            m_cat = NULL;
        }
    }
};

// 初始化
Cat *Cat::m_cat = NULL;

int main() {
    
    // 都是同一个cat
    Cat *cat1 = Cat::sharedCat();
    Cat *cat2 = Cat::sharedCat();
    Cat *cat3 = Cat::sharedCat();
    Cat *cat4 = Cat::sharedCat();
//    Cat::deleteCat();

    
//    Cat *cat5 = cat1->sharedCat();
//    delete cat5;

    std::cout << cat1 << std::endl; // 0x10044c2a0
    std::cout << cat2 << std::endl; // 0x10044c2a0
    std::cout << cat3 << std::endl; // 0x10044c2a0
    std::cout << cat4 << std::endl; // 0x10044c2a0
    
    getchar();
    return 0;
}
