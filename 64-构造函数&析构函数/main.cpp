//
//  main.cpp
//  64-构造函数&析构函数
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using namespace std;


class Test {
  
public:
    Test(float a, float b); // 有参的构造函数的声明
    float sum();            // 求和函数
    void scan(float a, float b);            // 输入函数 输入2个值
    void Print();           // 输出函数
    ~Test();
    
private:
    float x, y;
};

// 有参的构造函数的实现
Test::Test(float a, float b) {
    x = a;
    y = b;
}

// 成员函数 求和
float Test::sum() {
    return x + y;
}

// 成员函数 输入两个值
void Test::scan(float a, float b) {
    x = a;
    y = b;
}

// 成员函数 输出函数
void Test::Print() {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

// 析构函数
Test::~Test() {
    // 无参数  无返回值  
}

int main() {
   
    Test test1(2.0, 3.0);
    test1.Print();
    
    Test test2(3.0, 4.0);
    test2.scan(5.0, 10.0); // 重新赋值
    test2.Print();
    
    getchar();
    return 0;
}
