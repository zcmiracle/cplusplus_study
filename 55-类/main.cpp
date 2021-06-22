//
//  main.cpp
//  55-类
//
//  Created by XFB on 2021/6/22.
//

#include <iostream>
using namespace std;


class Animal {
public:
    char people[10];    // 人
    char lion[10];      // 狮子
    char eagle[10];     // 老鹰
     
}; // 类的主体是在 {} 中间，最后需要加一个分号;

class MyClass {
    
    int d = 50; // 1、如果没有修修饰符，默认的情况是私有的
                // 2、作用域：从访问修饰符开始到下一个访问修饰符
    
public:         // 公有数据和函数
    int a = 10;
    void print();

private:        // 私有数据和函数（我类里的成员和函数才可以访问）
    int b = 20;
    
protected:      // 保护数据和函数，所继承的派生类(子类)可以访问
    int c = 30;
    
};

void MyClass::print() {
    cout << "hello workd" << endl;
}


/**
 构造函数：为对象分配空间
 构造函数：无参构造 + 有参构造
 构造函数函数名要跟类名一致，没有类型，也没有返回值
 
 1、如果不写构造函数，编译器会自动生成，如果写了，则调用你缩写的构造函数
 2、构造函数氛围 有参构造 + 无参构造2中情况，如果是有参构造，你在创建对象的时候，记得也要传递参数
 */
class Time {
public:
    // 构造函数，此处写的是函数声明
    Time();
};

// 构造函数实现
Time::Time() {
    cout << "这是一个构造函数Time()" << endl;
}



/**
 构造函数：无参构造 + 有参构造
 构造函数函数名要跟类名一致，没有类型，也没有返回值
 
 1、如果不写构造函数，编译器会自动生成，如果写了，则调用你缩写的构造函数
 2、构造函数氛围 有参构造 + 无参构造2中情况，如果是有参构造，你在创建对象的时候，记得也要传递参数
 */
class Max {
public:
    Max(int a, int b);          // 2个参数的构造函数
    Max(int a, int b, int c);   // 3个参数的构造函数
    
    int maxFunc1();             // 成员方法1or成员函数
    int maxFunc2();             // 成员函数2
private:
    int x, y, z;
};

// 构造函数的实现
Max::Max(int a, int b) {
    cout << "这是两个参数的参构造函数" << endl;
    x = a;
    y = b;
}

Max::Max(int a, int b, int c) {
    cout << "这是三个参数的构造函数" << endl;
    x = a;
    y = b;
    z = c;
}


// Max:: 添加作用域
int Max::maxFunc1() {
    return x > y ? x : y;
}

int Max::maxFunc2() {
    return (x > y) ? (x>z?x:z) : (y>z?y:z);
}

int main() {

    MyClass A;
    cout << A.a << endl;
    A.print();
    
    Time time;
    
//    cout << A.b << endl; // 'b' is a private member of 'MyClass'
//    cout << A.c << endl; // 'c' is a protected member of 'MyClass'
//    cout << A.d << endl; // 'd' is a private member of 'MyClass'
    
    
    // 构造函数的重载：根据参数列表的个数 和 类型，来匹配响应的构造函数
    Max m1(10, 20);
    cout << "最大值是：" << m1.maxFunc1() << endl;
    
    Max m2(10, 20, 30);
    cout << "最大值是：" << m2.maxFunc2() << endl;

    getchar();
    return 0;
}
