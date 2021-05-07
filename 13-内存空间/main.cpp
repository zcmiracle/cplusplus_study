//
//  main.cpp
//  13-内存空间
//
//  Created by XFB on 2021/5/7.
//

#include <iostream>
using namespace std;

void test1() {
    
    // 未被初始化？？？在mac平台上，是被初始化了，在window上没有？
    int *p0 = new int;
    // 被初始化为0
    int *p1 = new int();
    // 被初始化为5
    int *p2 = new int(5);
    // 数组元素未被初始化
    int *p3 = new int[3];
    // 3个数组元素都被初始化为0
    int *p4 = new int[3]();
    // 3个数组元素都被初始化为0
    int *p5 = new int[3]{};
    // 数组首元素初始化为5，其他元素被初始化为0
    int *p6 = new int[3]{5};

    cout << *p0 << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;
    cout << *p5 << endl;
    cout << *p6 << endl;

}

struct Person {
    int m_id;
};

// 全局区
Person g_person;

int main() {

//    test1();

    // 栈空间
    Person person;
    
    // 堆空间
    Person *p = new Person;
    
    getchar();
    return 0;
}
