//
//  main.cpp
//  58-友元函数
//
//  Created by XFB on 2021/6/23.
//

#include <iostream>
using namespace std;

class computer {
public:
    char Name[20] = "MacOSX";           // 电脑名称
    void getPrice(double f);            // 普通成员函数，用来获取电脑的价格
    friend void print(computer MAC);    // 友元函数
    friend class MyComputer;            // 友元类
    
private:
    double Price = 20000;               // 电脑的价格
};


// 普通成员函数，用来获取电脑的价格
void computer::getPrice(double f) {
    Price = f;
}

// 友元函数
void print(computer MAC) {
    cout << "笔记本的价格是：" << MAC.Price << endl;
}

class MyComputer {
public:
    computer MAC;
    void print();
};

void MyComputer::print() {
    cout << "我的电脑品牌是：" << MAC.Name << endl;
    cout << "我的电脑价格是：" << MAC.Price << endl; // 可以访问Private中的成员
}


int main() {

    computer MAC;
    MAC.getPrice(15000);
    
    // 友元函数不是一个成员函数
    print(MAC);
    
    MyComputer PC;
    PC.print();
    
    getchar();
    return 0;
}
