//
//  main.cpp
//  22-成员访问权限
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>


/**
 成员访问权限：继承方式有3中
 public：公共的，任何地方都可以访问（struct默认）
 protected：子类内部、当前类内部可以访问 ***
 private：私有的，只有当前类内部可以访问（class默认）
 
 子类内部访问父类成员的权限，是以下2项中权限最小的那个
 1、成员本身的访问权限
 2、上一级父类的继承方式
 
 开发中一般用public，或者是public用的最多，这样可以保留父类原来的成员访问权限。
 
 *****【访问权限不影响对象的 内存布局 】*****
 */


struct Person {
//private:
//protected:
    int m_age;
    
private:
    void run() {
        // 当前类内部访问
        m_age = 10;
    }
};



// private Person 私有继承
// 相当于内部加上private: 所以Student的子类不可以访问
//struct Student : private Person {
struct Student : public Person {
    void study() {
        // 子类可以访问
        m_age = 20;
    }
};



// GoodStudent 能不能访问父类的属性，取决于Person和Student的最小值 private protected public
struct GoodStudent : protected Student {
  
    void work() {
        // 因为Student是private Person 私有继承，只能Student自己能够访问，子类不能访问
        m_age = 30;
    }
};

int main() {

    Person person;
    // protected的时候 不可访问
//    person.m_age = 10;
    
    
    Person *pp = new Person[5];
    // pp 是指针
    std::cout << pp->m_age << std::endl;
    // pp[0] 是对象
    std::cout << pp[0].m_age << std::endl;
    std::cout << pp[1].m_age << std::endl;
    // (*(pp + 1)) 等价于=> pp[1]
    std::cout << (*(pp + 1)).m_age << std::endl;
    
    getchar();
    return 0;
}
