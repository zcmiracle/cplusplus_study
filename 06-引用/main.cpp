//
//  main.cpp
//  06-引用
//
//  Created by XFB on 2021/4/28.
//

#include <iostream>
using namespace std;

int main() {

    int age = 10;
    int height = 20;
    
    // 引用
    int &refAge = age;
    refAge = 30;
    refAge = height;
    cout << age << endl;
    
    
    getchar();
    return 0;
}
