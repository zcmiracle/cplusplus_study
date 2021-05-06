//
//  main.cpp
//  08-引用和const补充
//
//  Created by XFB on 2021/5/6.
//

#include <iostream>

using namespace std;


// 函数返回值 100
int func() {
    return 100;
}

int main() {

    int height = 20;
    int age = 10;
    
    // 引用不能修改指向
    // ref1不能修改指向，但是可以通过ref1间接修改所指向的变量
//    int & const ref1 = age; // 这样写没有任何意义
    int &ref1 = age;
    ref1 = 30;
    
    // ref2不能修改指向，不可以通过ref2间接修改所指向的变量
    int const &ref2 = age;
//    ref2 = 30;
    
        
    // 指针变量p1不能修改指向，可以利用指针变量p1间接修改所指向的变量
    int * const p1 = &age;
    // 这样写会报错，不能将p1的指向从age指向height
//    p1 = &height;
    *p1 = 30;
    
    // 指针变量 p2 可以修改指向，不可以利用指针变量p2间接修改所指向的变量
    int const *p2 = &age;
    p2 = &height;
//    *p2 = 50; // 会报错
    
    
    int age1 = 20;
    
    int a = 10;
    int b = 20;
    
    // 常引用可以指向临时数据
//    const int &refAge = 30;
    const int &refAB = a + b;
    const int &refFunc = func();
    
    
    int age2 = 10;
    const long &refA = age2;
    age2 = 30;
    
    cout << "age2  is  " << age2 << endl;
    cout << "refA  is  " << refA << endl;

    
    getchar();
    
    return 0;
}
