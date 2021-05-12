//
//  main.cpp
//  38-隐式构造
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>
using namespace std;

class Person {
    int m_age;
public:
    // 无参构造函数
    Person() {
        cout << "Person() - " << this << endl;
    }
    // 有参构造函数
    Person(int age) : m_age(age) {
        cout << "Person(int) - " << this << endl;
    }
    // 拷贝构造函数
    Person(const Person &person) {
        cout << "Person(const Person &person) - " << this << endl;
    }
    // 析构函数
    ~Person() {
        cout << "~Person() - " << this << endl;
    }
    // 打印
    void display() {
        cout << "display() - age is " << m_age << endl;
    }
};

void test1(Person person) {
    
}

Person test2() {
    return 40;
}

int main() {

//    test1(20);
//    test2();

    Person p1;
    p1 = 40;
    
    getchar();
    return 0;
}
