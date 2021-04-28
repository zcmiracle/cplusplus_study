//
//  main.cpp
//  05-const
//
//  Created by XFB on 2021/4/28.
//

#include <iostream>
using namespace std;


// 结构体
struct Date {
    int year;
    int month;
    int day;
};


struct Student {
    int age;
};


int main() {

//    const int age = 20;

//    Date date = {2021, 4, 28};
//    Date date1 = {2018, 8, 05};
//
//    Date *p = &date;
//    p->year = 2016;
//
//    // date.year = 2016
//    // 结构体本身访问成员用 . 点
//    // 如果指向结构体的指针，去访问结构体的成员用 -> 访问
//    cout << date.year << endl;
//
//    // *p 取出指针所指向的东西
//    (*p).month = 5;
//    cout << date.month << endl;
//
//    *p = date1;
//    cout << date.month << endl;

//    Date date = {2021, 4, 28};
//    Date date1 = {2018, 8, 05};
//
//    const Date *p = &date;
//    // 下面三句代码会报错
//    p->year = 2016;
//    (*p).month = 5;
//    *p = date1;

    
    int age = 10;
    int height = 30;
    
    // const 修饰的是其右边的内容
    
    // *p1是常量，p1不是常量
    const int *p1 = &age; // 下面这两句没有任何区别，位置可交换
    // *p2是常量，p2不是常量
    int const *p2 = &age;
    
    // p3是常量，*p3是常量
    int * const p3 = &age;
    
    // p4和p5没有区别都是常量，*p4和*p5也都是常量 都不可更改
    const int * const p4 = &age;
    int const *const p5 = &age;
    
    
    // const int *p1 = &age;
    // *p1 是常量 p1不是常量
//    *p1 = 20; // 报错
//    p1 = &height;
//    *p1 = 40; // 报错
    
 
    // int * const p3 = &age;
//    int *p33 = &age;
//    *p33 = 20; // age = 20;
//    p33 = &height;
//    *p33 = 40; // height = 40;
//    cout << "age = " << age << endl; // age = 20
//    cout << "height = " << height << endl; // height = 40

    
    // int * const p3 = &age;
//    *p3 = 20; // age = 20;
//    // p3 是常量不可修改，*p3 是常量可以修改
//    p3 = &height;
//    *p3 = 40; // height = 40;
//    cout << "age = " << age << endl; // age = 20
//    cout << "height = " << height << endl; // height = 40

    
    // const int * const p4 = &age;
//    *p4 = 20; // 报错
//    p4 = &height; // 报错
//    *p4 = 40; // 报错
    
    
    
    Student stu1 = {10};
    Student stu2 = {20};
    
    // *pStu1是常量，pStu1不是常量
    const Student *pStu1 = &stu1;
//    *pStu1 = stu2; // 报错 不能被赋值
//    // 禁止使用指针去访问它所指向的存储空间
//    (*pStu1).age = 30; // 报错
//    pStu1->age = 30; // 报错
    pStu1 = &stu2;
    
    
    // pStu2是常量，*pStu2不是常量
    Student * const pStu2 = &stu2;
    *pStu2 = stu1;
    (*pStu2).age = 30;
    pStu2->age = 30;
//    pStu2 = &stu1; // 报错
    
    
    
    
    
 
    
    getchar();
    return 0;
}




#if 0


//    Date date = {2021, 4, 28};
//  如果const 修饰date不能修改，直接会报错
    const Date date = {2021, 4, 28};
    Date date1 = {2018, 08, 05};
    date = date1;
    
#endif
