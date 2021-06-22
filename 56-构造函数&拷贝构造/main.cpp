//
//  main.cpp
//  56-构造函数&拷贝构造
//
//  Created by XFB on 2021/6/22.
//

#include <iostream>
using namespace std;

class number {

public:
    number();               // 默认构造函数
    number(int i);          // 有参构造函数
    number(number&copy);    // 拷贝构造函数

    void print();           // 输出函数
    void print(number obj); // 重载输出函数
    
private:
    int *p;                 // 指针
};


// 默认构造函数
number::number() {
    cout << "我是默认构造函数" << endl;
}

// 有参构造函数
number::number(int i) {
    cout << "我是有参构造函数" << endl;
    p = new int; // 给指针p申请内存
    *p = i; // 形参赋值给地址p中值
}

// 我是拷贝构造函数
number::number(number&copy) {
    cout << "我是拷贝构造函数" << endl;
    p = new int;
    *p = *copy.p; // 值拷贝
}

// 输出函数
void number::print() {
    cout << "值：" << *p << endl;
}

// 重载输出函数
void number::print(number obj) {
    cout << "值：" << *obj.p << endl;
}



int main() {
    
    number n1;
    number n2(5);
    n2.print();
    
    number n3(10);
    n3.print();
    
    number n4(n2); // 拷贝构造函数
    n4.print();
    
    getchar();
    return 0;
}
