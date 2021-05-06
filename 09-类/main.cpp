//
//  main.cpp
//  09-类
//
//  Created by XFB on 2021/5/6.
//

#include <iostream>
using namespace std;

/**
 struct 和 class 的区别

 struct 的默认成员权限是public
 class 的默认权限是private
 
 */


struct Person {
    
//private:
    // 成员变量（属性）
    int age;
    
    // 成员函数（方法）
    void run() {
        cout << "Person::run() - " << age << endl;
    }
};

class Person1 {
    // 成员变量（属性）
    int age;
    
    // 成员函数（方法）
    void run() {
        cout << "Person::run() - " << age << endl;
    }
};

int main() {

    // 利用类创建对象
    Person person;
    person.age = 20;
    person.run();
    
    
    
    
    getchar();
    return 0;
}
