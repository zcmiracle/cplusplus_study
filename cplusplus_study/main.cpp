//
//  main.cpp
//  CPlusPlus_study
//
//  Created by XFB on 2021/4/27.
//

#include <iostream>

// 先命名std 才能使用cout
// cout << "Hello, world!!!" << endl;
using namespace std;

// cout、cin
void test() {

    // 输出 cout
    cout << "Hello";
    cout << "\n";
    cout << "World";
    cout << "\n";

    cout << "Hello, world!";
    cout << endl;
    
    // endl 结束换行 等价于 "\n"
    // 下面这句代码 等价于 上面两句
    cout << "Hello, world!" << endl;

    // cin 从键盘接收东西
    
    cout << "Please type a number: " << endl;
    
    int age;
    cin >> age;
    cout << "age is " << age << endl;


    cout << "Please entry name: " << endl;
    string name;
    cin >> name;
    cout << "my name is " << name << endl;
    
    // 等待键盘输入（如果敲回车，就会读取键盘输入）
    getchar();
}

int main() {
    
    std::cout << "Hello, World!" << endl;

    return 0;
}



