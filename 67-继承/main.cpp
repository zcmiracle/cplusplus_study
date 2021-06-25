//
//  main.cpp
//  67-继承
//
//  Created by XFB on 2021/6/25.
//

#include <iostream>
using namespace std;


class A {
public:
    int x;
protected:
    int y;
private:
    int z;
};


class B : public A {        // B类公开继承A类
public:
    void print() {
        cout << x << endl;
        cout << y << endl;
        // 'z' is a private member of 'A'
//        cout << z << endl;
    }
};

class C: private A {        // C类以私有的方式继承A类
public:
    void print() {
        cout << x << endl;  // 类内可以访问 私有继承的 公开成员
        cout << y << endl;  // 类内可以访问 私有继承的 保护成员
//        cout << z << endl;// 类内不可以访问 私有继承的 私有成员
    }
};

// 主要是这个 private 继承过来就是私有的了，所以下面访问不了
class D: private C {
public:
    void print() {
//        cout << x << endl;    // 'x' is a private member of 'A'
//        cout << y << endl;    // 'y' is a private member of 'A'
//        cout << z << endl;    // 'z' is a private member of 'A'
    }
};


// ==========================================

class Student {
    
//public:
//    void Print() {
//        cout << "num:" << endl;
//        cout << "name:" << endl;
//        cout << "sex:" << endl;
//        cout << "age:" << endl;
//        cout << "addr:" << endl;
//    }
//
//private:
//    int num;            // 学号
//    char name[20];      // 名字
//    char sex;           // 性别
//    // 新增属性
//    int age;            // 年龄
//    char addr[20];      // 地址
//};
    
public:
    void Print() {
        cout << "num:" << endl;
        cout << "name:" << endl;
        cout << "sex:" << endl;
    }

private:
    int num;            // 学号
    char name[20];      // 名字
    char sex;           // 性别
};


// 类的继承
class GoodStudent: public Student { // GoodStudent 继承自 Student
  
public:
    void Print1() {
        cout << "age:" << endl;
        cout << "addr:" << endl;
    }
    
private:
    int age;        // 新增属性 年龄
    string addr;    // 新增属性 地址
};


int main() {
    
    Student s1;
    s1.Print();
    
    
    GoodStudent s2;
    s2.Print();
    s2.Print1();
    
    
    
//    B b;
//    b.x;
    
    C c;
//    c.x; c.y; c.z; // 类外都不可以引用
    
    getchar();
    return 0;
}
